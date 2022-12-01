#ifndef GAME_H
#define GAME_H

#include <stdio.h>

typedef struct game Game;

Game* create_game();

Game* add_game(FILE *file);

void print_game(Game *game);

void free_game(Game *game);


#endif