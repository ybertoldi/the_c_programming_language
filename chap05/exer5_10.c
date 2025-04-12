#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define SIZE 100

double stack[SIZE];
int sp = 0;

void push(double d);
double pop(void);
int evaluate(char* s);

void push(double d){
    if (sp < SIZE){
        stack[sp++] = d;
    } else 
        printf("stack is full, cannot push any value.");
}
double pop(){
    if (sp > 0){
        return stack[--sp];
    } else
        printf("stack is empty. Cannot pop.");
}

int evaluate(char* s){
    if (isdigit(*s)){
        int i = 1;
        char c;
        while ((c = *(s+(i++))) != '\0'){
            if (!isdigit(c))
                return -1;
        }
        push(atoi(s));
        return 1;
    }

    double temp;
    switch (*s){
        case '+':
            push(pop() + pop());
            return 1;
        case '-':
            temp = pop();
            push(pop() - temp);
            return 1;
        case '*':
            push(pop() * pop());
            return 1;
        case '/':
            temp = pop();
            push(pop() / temp);
            return 1;
        default:
            return -1;
    }
}

int main(int argc, char *argv[])
{
    int i = 1;
    int error = 0;
    while (i < argc)
    {
        if (evaluate(argv[i]) < 0){
            error = 1;
            break;
        }
        i++;
    }
    
    if (error){
        printf("error at argument %d. \"%s\" is not a valid expression.", i+1, argv[i]);
    } else{
        printf("\t= %.5f", pop());
    }

    return 0;
}
