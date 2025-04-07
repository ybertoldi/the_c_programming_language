#include <stdio.h>

long long power(long a, long b){
    static long long cache[60] = {0};
    if (cache[b]){
        return cache[b];
    }
    
    long long res;
    if (b == 0){
        return 1;
    }
    
    if (b % 2 == 0){
        long long val = power(a, b/2);
        res = val * val;
        cache[b] = res;
        return res;
    }

    res = a * power(a, b -1);
    cache[b] = res;
    return res;
}

int lenString(char s[]){
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;   
}


long long htoi(char s[]){
    char c;
    int i = lenString(s) - 1;
    long long n = 0;
    int exp = 0;

    while (i >= 0){
        c = s[i];
        if (c >= '0' && c <= '9'){
            n += power(16, exp) * (c - '0');
        }
        else if (c >= 'A' && c <= 'F'){
            n += power(16, exp) * (10 + c - 'A');
        }
        else if (c >= 'a' && c <= 'f'){
            n += power(16, exp) * (10 + c - 'a');
        }
        
        i--;
        exp++;
    }

    return n;
}

int main(){
    char hex[] = "14092B96CA";
    long long n = htoi(hex);
    printf("%lld\n", n);
    printf("%lld", 0X14092B96CA);

    return 0;
}
