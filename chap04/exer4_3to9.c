#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100 /* maximum space on stack */
#define BUFSIZE 100 /* buffer for ungetch */


int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;   /* next free position in buf */


int getch(void);
void ungetch(int c);

int getop(char []);
void push(double);
double pop(void);

int getch(){
    return (bufp > 0)? buf[--bufp] : getchar();
}
void ungetch(int c){
    if (bufp >= BUFSIZE){
        printf("ungetch: too many characters\n");
    } else{
        buf[bufp++] = c;
    }
}


void push(double d){
    if (sp < MAXVAL){
        val[sp] = d;
        sp++;
    } else {
        printf("ERROR: stack is full, can't push any more numbers\n");
    }
}
double pop(){
    if (sp > 0){
        sp--;
        return val[sp];
    } else{
        printf("ERROR: Stack is empty. Cannot pop any number from it\n");
        return 0.0;
    }
}
int getop(char s[]){ /* get next number or operator from user input */
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t') /* while user is only typing spaces or tabs, do nothing.*/
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-'){
        return c;
    }

    i = 0;
    if (c == '-'){
        c = getch();
        s[++i] = c;
    }

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


int main(){
    int type;
    double op2;
    int opi1, opi2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF){
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0){
                push( pop() / op2);
            }else{
                printf("ERROR: zero divisior\n");
            }
            break;
        case '%':
            op2 = pop();
            push(((int) pop()) % ((int) op2));
            break;
        case '\n':
            printf("\t = %.8g\n", pop());
            break;
        default:
            break;
        }
    }
}

