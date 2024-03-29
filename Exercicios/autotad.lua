-- Get the c file name. Adds '.c' when necessary
function check_filename_c(filename)

    new_name_c = filename
    if not filename:find("%.c") then
       new_name_c = filename..".c" 
    end
    return new_name_c

end

-- Returns the header file name
function get_filename_h(filename)
    return filename:gsub("%.c", ".h")
end

-- Adapt line to be written in the header file
function adapt_line(string, prev_string)
    
    -- Structs are defined by typedef and named by their original name capitalized
    idx_s, idx_e = string:find("struct")
    if idx_s ~= nil then
        new_string = string.match(string:sub(idx_e+2, #string), "%w*")
        new_string = "typedef struct "..new_string.." "..new_string:gsub("^%l", string.upper)..";\n"

    elseif (string.char(string.byte(string, string:find("%g"))) ~= "{") then
        new_string = string:gsub("{", ";\n")

    else
        -- In case the first alphanumeric character in string is "{", 
        -- new_string, used for function's or struct's name, receives prev_string
        if prev_string:find("struct") then
            new_string = adapt_line(prev_string)
        else 
            new_string = prev_string..";\n"
        end

    end

    return new_string
end

-- Writes header in the header file
function write_header(filename_h, file_h_w)

    -- Prepares ADTFile name for writing
    header_filename = string.upper(filename_h):gsub('%.','_')

    str_header = "#ifndef "..header_filename.."\n#define "..header_filename.."\n\n"

    file_h_w:write(str_header)

end

-- Writes the contents in the header file
function write_contents(file_c_r, file_h_w, comment_off, dict_functions_comments, typedef_list, include_list)
    
    if comment_off == true then
        default_comment = "\n"
    else
        default_comment = "\n/*\n * Comment section\n*/\n"
    end

    for k, line in pairs(include_list or {}) do
        file_h_w:write(line.."\n")
    end

    for k, line in pairs(typedef_list or {}) do
        file_h_w:write("\n"..dict_functions_comments[line])
        file_h_w:write(line.."\n")
    end

    -- curly_braces_control makes the scope control to identify functions
    curly_braces_control = 0

    i = 0
    line = file_c_r:read("*line")
    prev_line = line
    while line do

        -- If "AUTOTAD_PRIVATE" is in line, curly_braces_control is changed so the next function will be ignored by the script
        if (line:find("AUTOTAD_PRIVATE") and curly_braces_control == 0) then
            curly_braces_control = -1

        elseif line:find("{") then

            if curly_braces_control == 0 and not line:find("static") then
                line = adapt_line(line, prev_line)

                -- Getting function name as key
                if not line:find("struct") and not line:find("typedef") then
                    key_start = line:find(" ") + 1
                    key_end = line:find("%(") - 1
                    key = string.match(line:sub(key_start, key_end), "%g*")
                else
                    key = line:match("[^\n]*")
                end

                -- If line already existed in a previous file, it's original comment is kept in the new one
                str_comment_section = default_comment
                pcall( function()
                            if dict_functions_comments[key] then
                                str_comment_section = "\n"..dict_functions_comments[key]
                            end
                        end )

                file_h_w:write(str_comment_section)
                file_h_w:write(line)

            end
                
            -- If AUTOTAD_PRIVATE is active, curly_braces_control is decremented
            if curly_braces_control >= 0 then 
                curly_braces_control = curly_braces_control + 1
            else
                curly_braces_control = curly_braces_control - 1
            end
                
        end

        if line:find("}") then
            if curly_braces_control >= 0 then 
                curly_braces_control = curly_braces_control - 1
            elseif curly_braces_control < 0 then
                curly_braces_control = curly_braces_control + 1
            end
            
            -- If curly_braces_control == -1 after finding '}', AUTOTAD_PRIVATE is scope is over
            if curly_braces_control == -1 then curly_braces_control = 0 end

        end

        -- Checks whether there is a alphanumeric character in line to store in prev_line
        if(line:match("%w")) then prev_line = line end
        line = file_c_r:read("*line")

    end

end

-- Writes footer in the header file
function write_footer(file_h_w)
    file_h_w:write("\n\n#endif")
end

-- Writes header file from scratch
function write_new_hfile(filename_c, filename_h, comment_off, dict_functions_comments, typedef_list, include_list)

    -- Opening base file and checking whether it exists
    local file_c_r = io.open(filename_c, "r")
    if file_c_r == nil then return -1 end

    local file_h_w = io.open(filename_h, "w")

    write_header(filename_h, file_h_w)
    write_contents(file_c_r, file_h_w, comment_off, dict_functions_comments, typedef_list, include_list)
    write_footer(file_h_w)

    file_c_r:close()
    file_h_w:close()

    return 0
end

-- Writes header file from existent file
function hfile_from_existing_cfile(filename_c, filename_h, file_h_r, comment_off)

    -- First, the existent .h file is read and the functions' comments are stored in a dictionary
    dict_functions_comments = {}
    typedef_list = {}
    include_list = {}

    comment = ""
    comment_scope = false

    line = file_h_r:read("*line")
    while (line) do

        if (line:find("/%*") and not line:find("%*/") and comment_scope == false) then
            comment_scope = true
            comment = comment..line.."\n"

        elseif (line:find("%*/") or (line:find("//") and comment_scope == false)) then
            comment = comment..line.."\n"
            comment_scope = false
        
        elseif (comment_scope == true) then
            comment = comment..line.."\n"

        elseif (comment_scope == false and line:find("typedef") and not line:find("struct")) then
            dict_functions_comments[line] = comment
            table.insert(typedef_list, line)
            comment = ""

        elseif (comment_scope == false and line:find("#include") ) then
            table.insert(include_list, line)

        else
            -- Compares whether first character is '\n'
            if line:find("%w") and string.char(line:byte()) ~= "#" and not line:find("struct") and not line:find("typedef") then
                f_name_start = line:find(" ") + 1
                f_name_end = line:find("%(") - 1
                -- string.match is used to strip string in case there is blank spaces at the end
                f_name = string.match(line:sub(f_name_start, f_name_end), "%g*")

                dict_functions_comments[f_name] = comment
            else
                dict_functions_comments[line] = comment
            end
            comment = ""
        end

        line = file_h_r:read("*line")
    end

    -- Then, the previous file is overwritten by the new version, keeping the original comments
    write_new_hfile(filename_c, filename_h, comment_off, dict_functions_comments, typedef_list, include_list)

end

list_of_filenames = { c = {}, h = {} }
comment_off = false

-- Checks input from argv 
for i=1, #arg, 1 do

    if (arg[i] == "comment-off") then
        comment_off = true
    else
        table.insert(list_of_filenames.c, arg[i])
    end

end

-- If no filename is given via argv, asks as input
if #list_of_filenames.c == 0 then 
    inp = io.read("*l")
    table.insert(list_of_filenames.c, inp)
end

-- Adapt files names
for k, v in pairs(list_of_filenames.c) do
    list_of_filenames.c[k] = check_filename_c(v)
    list_of_filenames.h[k] = get_filename_h(list_of_filenames.c[k])
end

-- Execute program for each file given as an argument
for i=1, #list_of_filenames.c, 1 do

    local file_h_r = io.open(list_of_filenames.h[i],"r")

    -- If the header file already exists, the new one is created based on it
    if file_h_r then
        hfile_from_existing_cfile(list_of_filenames.c[i], list_of_filenames.h[i], file_h_r, comment_off)
        file_h_r:close()
    else
        if write_new_hfile(list_of_filenames.c[i], list_of_filenames.h[i], comment_off) ~= 0 then
            print("ERROR! File "..list_of_filenames.c[i].." not found.")
        end
    end

end
