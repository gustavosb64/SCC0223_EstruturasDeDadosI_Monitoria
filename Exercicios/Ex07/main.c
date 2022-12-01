#include "game.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    FILE *file = fopen("CSV-TodosJogos.csv", "r");
    if (file == NULL){
        printf("ERROR: file not found.\n");
        return 0;
    }

    Game *game; 
    game = add_game(file);
    while(game != NULL){
        print_game(game);
        free_game(game);
        game = add_game(file);
    }

    fclose(file);

    return 0;
}
