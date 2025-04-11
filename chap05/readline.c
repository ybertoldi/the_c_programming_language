#include <stdio.h>

int getline(char *s, int max){
    int c, i;
    i = 0;
    while (--max > 0 && (c = getchar()) != EOF && c != '\n'){
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}