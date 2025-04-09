#include <stdio.h>


int strend(char *s, char *t)
{
    while (*s != '\0'){
        if (*s == *t){
            char *t_s = s;
            char *t_t = t;
            while (*t_t == *t_s){
                if (*t_t == '\0')
                    return 1;
                t_t++;
                t_s++;
            }
        }
        s++;
    }
    return 0;

}

int main(){
    char *a = "bom dia, amigo";
    char *b = "amig";
    printf("%d", strend(a, b));
    return 0;
}