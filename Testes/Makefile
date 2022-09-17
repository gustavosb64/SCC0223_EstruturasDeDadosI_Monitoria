all:
	lua ../autotad.lua ponto.c caminho.c comment-off
	gcc -g -Wall -Wpedantic -o main *.c -lm

c:
	gcc -g -o main *.c -lm

run:
	./main

debug:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./main
