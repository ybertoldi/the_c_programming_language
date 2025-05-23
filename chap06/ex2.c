#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
int getword(char*, int);
struct tnode* addtree(struct tnode *p, char *w);
void treeprint(struct tnode *p);

int main(int argc, char const *argv[])
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;

    while (getword(word,MAXWORD) != EOF){
        if (isalpha(word[0])){
            root = addtree(root, word);
        }
    }
    treeprint(root);

    return 0;
}

