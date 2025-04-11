#include <stdlib.h>
#include <stdio.h>

char monthName(int n){
    static char *name[] = {
        "Illegal Month",
        "January", "Frebruary", "March", 
        "April", "May", "June", "July", "August",
        "October", "Novermber", "December"
    };

    return (n >= 1 && n <= 12)? name[n] : name[0];
}


