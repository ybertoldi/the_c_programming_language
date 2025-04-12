#define MAXSIZE_A 100000

static char arr[MAXSIZE_A];
static int i = 0;

char* copy_txt(char* s)
{
    int temp = i;
    while ((arr[i++] = *s++) != '\0')
        ;
    
    return &arr[temp];
} 
