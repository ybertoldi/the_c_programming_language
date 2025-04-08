#include <stdio.h>

int lenstr(char s[]){
    int i = 0;
    while (s[i] != '\0')
        i++;
    
    return i;
}

int strrrindex(char s[], char c[]){
    int i, j, k;

    for (i = lenstr(s); i >= 0; i--){
        j = i;
        k = 0;
        while (s[j] != '\0' && c[k] != '\0' && s[j] == c[k]){
            k++;
            j++;
        }
        
        if (c[k] == '\0'){
            return i;
        }
    }
    return -1;
}

int main(){
    char a[] = "alguns dos meus livros estão empoeirados.";
    char b[] = "meus";
    printf("%d", strrrindex(a, b));
}

