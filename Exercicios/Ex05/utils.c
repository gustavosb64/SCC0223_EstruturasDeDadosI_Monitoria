#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "utils.h"

char* read_word(){
    char *string = NULL;
    char currentInput;
    int index = 0;
    do {
        currentInput = (char)getchar();
        string = (char *) realloc(string, sizeof(char) * (index + 1));
        string[index] = currentInput;
        index++;
        if(currentInput == '\r')
        {
            currentInput = (char)getchar();
        }
    } while((currentInput != '\n') && (currentInput != ' ') && (currentInput != EOF));
    string[index - 1] = '\0';
    return string;
}

char* boolean_print(int value){
    if (value == 0) return "False";
    else return "True";
}
