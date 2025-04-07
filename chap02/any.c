#include <stdio.h>

int any(char s1[], char s2[]){
    for (int i = 0; s1[i] != '\0'; i++){
        for (int j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j])
                return i;
        }
        
    }

    return -1;
}

int main(){
    char a[] = "paralelepipedo";
    char b[] = "ocd";
    int idx = any(a, b);
    printf("%d", idx);
}