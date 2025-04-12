#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 1000
#define ARR_SIZE 1000
#define BUFSIZE 100000

char *lines[ARR_SIZE]; /* arr of strings */
int lp = 0; /* cur empty space on lines*/

int getline(char *line, int max);
void put(char *l);
char* copy_txt(char* s);

void put(char *l){
    lines[lp++] = copy_txt(l);
}

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    while (--argc > 0 && (*++argv)[0] == '-')
    {
        while (c = *++argv[0])
        {
            switch (c)
            {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find: illegal option %c\n");
                argc = 0;
                found = -1;
                break;
            }
        }
    }

    if (argc != 1)
    {
        printf("usage: find -x -n patters\n");
    }
    else
    {
        while (getline(line, MAXLINE) > 0)
        {
             if ((strstr(line, *argv) != NULL) != except)
            {
                put(line);
                found++;
            }
        }
    }

    for (int i = 0; i < lp; i++)
    {
        if (number)
            printf("%1d. ", i + 1);
        printf("%s \n", lines[i]);
    }

    return found;
}
