#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFERSIZE 100
#define SIZE 100

char buf[BUFFERSIZE];
int bsp = 0;

int getch(void);
void ungetch(int);

int getint(int*);

int getch(){
    return (bsp == 0)? getchar() : buf[bsp--];
}
void ungetch(char c){
    buf[bsp++] = c;
}


int getint(int *pn){
   int c, sign;

    while (isspace( c = getch()));
    
    if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetc(c);
        return 0;
    }
    sign = (c == '-')? -1: 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;

    if (c != EOF)
        ungetch(c);
    return c;

}