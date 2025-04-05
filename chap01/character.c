#include <stdio.h>

int main(){
    int c;

    c = getchar();
    putchar(49);
    while (c != EOF)
    {
        putchar(52);
        putchar('b');
        c = getchar();
    }
    
}