#include <stdio.h>
#include <stdlib.h>

int main(){

    //char *s = malloc(0);
    char *s = malloc(3);
    printf("%p: %p\n", &s, s);

    scanf(" %s",s);
    printf("%p: %p\n", &s, s);
    printf("%s\n",s);

    printf("-> %d\n",s[3]);
    printf("-> %d\n",s[4]);
    scanf(" %s",s);

    printf("-> %d\n",s[4]);

    printf("%p: %p\n", &s, s);
    printf("%s\n",s);
    printf("-> %d\n",s[2]);
    printf("-> %d\n",s[3]);


    /*
    printf("%d\n",s[50]);
    for (int i=0; i<10000; i++){
        if (s[i] != 0)
            //printf("%d %c\n",s[i], s[i]);
            printf("%d\n",s[i]);
    }

    printf("%d\n",s[100]);
    */


    return 0;
}
