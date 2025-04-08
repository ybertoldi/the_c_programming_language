#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define DO_NOTHING -999 /* signals switch to do nothing */
#define INVALID 'I' /* invalid synthax */
#define NUMBER '0' /* signal that a number was found */
#define MAXOP 100 /* max size of operand or operator */

#define MAXVAL 100 /* maximum space on stack */
#define BUFSIZE 100 /* buffer for ungetch */

#define V_SIZE 26 /* store value for 26 variables a-z */
#define NO_VARIABLE -1 /* default value of curVariable */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;   /* next free position in buf */

double variables[V_SIZE];
int curVariable = NO_VARIABLE;

//BUFFER
int getch(void);
void ungetch(int c);

//STACK
void push(double);
double pop(void);
double peek(void);
void duplicateTop();
void swaptwotop();

//READ INPUT
int getop(char []);

//PARSE INPUT
int strEquals(char[], char[]);
int validateOperation(char[], int);

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
double peek(){
    if (sp > 0){
        return val[sp-1];
    }else{
        printf("peek: no element in stack\n");
        return 0.0;
    }
}
void duplicateTop(){
    if (sp == 0){
        printf("duplicateTop: no element to duplicate on stack\n");
    } else if (sp >= MAXVAL){
        printf("duplicateTop: stack is full\n");
    } else{
        val[sp] = val[sp-1];
        sp++;
    }
}
void swaptwotop(){
    if (sp <= 1){
        printf("swaptwotop: not enough elements to swap\n");
    } else {
        double temp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;
    }
}



int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t') /* while user is only typing spaces or tabs, do nothing.*/
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
    {
        if (isalpha(c)){
            return validateOperation(s, c);
        }
        return c;
    }

    i = 0;
    if (c == '-')
    {
        c = getch();
        s[++i] = c;
    }

    if (isdigit(c))
    {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    if (c == '.')
    {
        while (isdigit(s[++i] = c = getch()))
            ;
    }

    s[i] = '\0';
    if (c != EOF)
    {
        ungetch(c);
    }

    return NUMBER;
}

int strEquals(char s[], char t[]){
    int i = 0;
    while (s[i] != '\0' && t[i] != '\0' && s[i] == t[i]){
        i++;
    }
    return s[i] == t[i];
}
int validateOperation(char s[], int c){
    int i = 0;
    s[i++] = tolower(c);
    while (i < MAXOP - 1 && isalpha(c = getch())) {
        s[i++] = tolower(c);
    }
    s[i] = '\0';
    
    if (c != EOF)
        ungetch(c);

    if (i == 1 ){
        
        if (c == ' '){
            while ((c = getch()) == ' ' || c == '\t');
        }

        if (c == '='){
            if (s[0] >= 'a' && s[0] <= 'z'){
                curVariable = s[0];
            } else {
                printf("Syntax error. '%c' is not a valid variable.", s[0]);
            }

            return DO_NOTHING;
        } else{
            ungetch(c);
            if (s[0] >= 'a' && s[0] <= 'z'){
                push(variables[s[0] - 'a']);
            } else {
                printf("Syntax error. '%c' is not a valid variable.", s[0]);
            }
            return DO_NOTHING;
        }
    }

    if (strEquals(s, "sin")) return 's';
    if (strEquals(s, "cos")) return 'c';
    if (strEquals(s, "pow")) return 'p';
    if (strEquals(s, "exp")) return 'e';
    
    return INVALID;
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
        case 's':
            push(sin(pop()));
            break;
        case 'c':
            push(cos(pop()));
            break;
        case 'p':
            op2  = pop();
            push(pow(pop(), op2));
            break;
        case 'e':
            push(exp(pop()));
            break;
        case '\n':
            op2 = pop();
            if (curVariable != NO_VARIABLE){
                variables[curVariable - 'a'] = op2;
                curVariable = NO_VARIABLE;
            }
            printf("\t = %.8g\n", op2);
            break;
        default:
            break;
        }
    }
}

