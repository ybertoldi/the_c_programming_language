#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int found = 0;
    if(argc != 2)
        printf("Usage: find patter\n");
    else{
        scanf("%s", line);
        while(strlen(line) > 0){
            if (strstr(line, argv[1]) != NULL){
                printf("%s", line);
                found++;
            }
            scanf("%s", line);
        }
    }
    return found;
}