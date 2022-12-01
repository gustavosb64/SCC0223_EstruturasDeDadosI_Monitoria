#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "utils.h"

#define BUFFER 4096
char *readline(FILE *stream) {
    char *string = NULL;
    int pos = 0;

	do{
        if (pos % BUFFER == 0) {
            string = (char *) realloc(string, (pos / BUFFER + 1) * BUFFER);
        }
        string[pos] = (char) fgetc(stream);

        if (string[pos] == '\r')
            string[pos] = (char) fgetc(stream);

    }while(string[pos++] != '\n' && string[pos-1] != ';' && !feof(stream));

    string[pos-1] = '\0';
    string = (char *) realloc(string, pos); // (pos-1) caso haja '\r'

    if (strlen(string) == 0){
        free(string);
        string = NULL;
    }

    return string;
}
