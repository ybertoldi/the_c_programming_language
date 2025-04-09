#include <stdio.h>
#include <string.h>

/*
read all the lines from the input
sort them
print the in order
*/

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readLines(char *lineptr, int nlines);
void writeLines(char *lineptr[], int left, int nlines);

void qsort(char *lineptr[, int left, int right]);

int main()
{
    int nlines;
    if ((nlines = readLines(lineptr, MAXLINES)) >= 0)
    {
        qsort(lineptr, 0, nlines-1);
        writeLines(lineptr, nlines);
        return 0;
    } else {
        printf("ERROR: INPUT TOO BIG TO SORT");
        return 1;
    }
}

#define MAXLEN 1000
int getline(char *, int);
char* alloc(int);

int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN))){
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else{
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writeLines(char *lineptr[],  int nlines){
    int i;
    for(i = 0; i < nlines; i++){
        printf("%s\n", lineptr[i]);
    }
}