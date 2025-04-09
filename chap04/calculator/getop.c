#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[]){ /* get next number or operator from user input */
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t') /* while user is only typing spaces or tabs, do nothing.*/
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.'){
        return c;
    }

    i = 0;
    if (isdigit(c)){
        while (isdigit(s[++i] = c = getch()));
    }
    if (c == '.'){
        while (isdigit(s[++i] = c = getch()));
    }
    s[i] = '\0';
    if (c != EOF){
        ungetch(c);
    }
    return NUMBER;

}