UTIL=Racional/racional.c
MAIN=main.c
BINARY=batata

all:
	gcc -Wall -Werror -g $(UTIL) $(MAIN) -o $(BINARY)

run:
	./$(BINARY)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)
