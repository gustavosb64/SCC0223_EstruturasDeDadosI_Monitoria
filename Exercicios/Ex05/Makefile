UTIL = LargeNumber/linked_list.c LargeNumber/large_number.c Utils/utils.c
MAIN = main.c
BINARY = main

all:
	gcc -Wall $(MAIN) $(UTIL) -o $(BINARY) 

c:
	gcc $(MAIN) $(UTIL) -o $(BINARY) 

run:
	./$(BINARY)

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(BINARY)
