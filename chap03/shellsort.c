#include <stdio.h>

void shellSort(int v[], int n){
   int i, j, gap, temp;

    for (gap = n/2; gap > 0; gap /=2)
    {
        for (i = gap; i < n; i++){
            for (j=i-gap; j>=0; j--){
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
        }
    }
    
}

int main(){
    int v[] = {3,2,5,6,9,10,22,1};
    int n = sizeof(v) / sizeof(int);
    shellSort(v,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }

}