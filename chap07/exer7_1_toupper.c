#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int c, new_c;
  int tcase;

  if (argc <= 1) {
    printf("please enter '-l' to use lowercase or '-u' to use upper case");
    tcase = -1;
  } else {
    if (strcmp(argv[1], "-l") == 0) {
      tcase = 1;
    } else if (strcmp(argv[1], "-u") == 0) {
      tcase = 2;
    } else {
      printf("wrong argument, use '-l' or '-u'");
    }
  }

  if (tcase >= 0) {
    while ((c = getchar()) != EOF) {
      new_c = (tcase == 1)? tolower(c) : toupper(c); 
      putchar(new_c);
    }
  }
  return 0;
}
