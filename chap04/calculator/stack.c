#include <stdio.h>
#include "calc.h"
#define MAXVAL 100
static int sp = 0;
static double val[MAXVAL];

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