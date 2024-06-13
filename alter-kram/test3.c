/* echo_char.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int c;

   while( (c = getchar()) !='.')
      printf(" Die eingegebene Taste lautet: %c \n", c);
      //putchar(c);
   return EXIT_SUCCESS;
}
