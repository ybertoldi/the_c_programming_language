#include <stdio.h>
#include <string.h>

/*
read all the lines from the input
sort them
print the in order
*/

#define MAXLINES 5000
#define MAXLEN 1000
#define ALLOCSIZE 100000

char allocbuf[ALLOCSIZE];
char *allocp = allocbuf;

char *lineptr[MAXLINES];

int getline(char *, int);
char* alloc(int);

int readlines(char *lineptr[], int nlines);
void writeLines(char *lineptr[],  int nlines);

void qsort(char *lineptr[], int left, int right);
void swap(char *v[], int i, int j);

char* alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    } else 
        return 0;
}
void afree(char *p){
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}


int getline(char *s, int lim){
    int n = 0;
    char c;

    while (n < lim && (s[n++] = c = getchar()) != '\n')
        ;
    return n;
}


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


void qsort(char *v[], int left, int right)
{
    int i, last;
    if (left >= right)
        return;
    
    swap(v, left, (left+right)/2);
    last = left;
    for (i = left+1; i < right; i++){
        if (strcmp(v[i], v[left]) < 0){
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}
void swap(char *v[], int i, int j){
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


int main()
{
    int nlines;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort(lineptr, 0, nlines-1);
        writeLines(lineptr, nlines);
        return 0;
    } else {
        printf("ERROR: INPUT TOO BIG TO SORT");
        return 1;
    }
}


