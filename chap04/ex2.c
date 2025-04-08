#include <ctype.h>
#include <stdio.h>

double atof(char s[]){
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++);
    sign = (s[i] == '-')? -1: 1;
    
    if (s[i] == '-' || s[i] == '+')
        i++;
    
    for (val = 0.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
    }

    if (s[i] == '.'){
        i++;
    }else{
        return val * sign;
    }

    for (power = 10; isdigit(s[i]); i++){
        val += (s[i] - '0') / power;
        power *= 10;
    }

    return val * sign;
}

int main(){
    char s[] = "-1500.132";
    printf("%Lf", atof(s));
    return 0;
}