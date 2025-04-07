#include <stdio.h>


void squeeze(char s[], char c[]){
    int i, j, k;
    int cur_in_c;
    for (i = j = 0; s[i] != '\0'; i++){
        
        cur_in_c = 0;
        for (k = 0; c[k] != '\0'; k++){
            if (c[k] == s[i])
                cur_in_c = 1;
        }

        if (!cur_in_c){
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';

}

int main(){
    char a[] = "bom dia, meus amigos";
    char b[] = "ao";
    squeeze(a, b);
    printf("%s", a);
    return 0;
}