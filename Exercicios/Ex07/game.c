#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "utils.h"

struct game{
    char* name;
    char* company;
    int year;
};

Game* create_game(){

    Game *game = (Game *) malloc(sizeof(Game));
    game->name = NULL;
    game->company = NULL;
    game->year = -1;

    return game;
}

Game* add_game(FILE *file){

    char *name = readline(file);
    if (name == NULL){
        free(name);
        return NULL;
    }
    char *c_year = readline(file);
    char *company = readline(file);

    Game *game = create_game();

    game->name = name;
    game->company = company;
    game->year = atoi(c_year);
    free(c_year);

    return game;
}

void print_game(Game *game){

    printf("Name: %s\n", game->name);
    printf("Year: %d\n", game->year);
    printf("Company: %s\n", game->company);
    printf("\n----------------------\n");

    return;
}

void free_game(Game *game){
    free(game->name);
    free(game->company);
    free(game);
    return;
}
