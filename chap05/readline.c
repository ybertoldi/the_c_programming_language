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

int readlines(char *lineptr[], int nlines){
    int i = 0;
    while (getline(lineptr[i], 10000) > 0)
    {
        i++;
    }
    return i;
}

void writelines(char* lineptr[], int nlines){
    for (int i = 0; i < nlines; i++){
        printf("%s", lineptr[i]);
    }
}