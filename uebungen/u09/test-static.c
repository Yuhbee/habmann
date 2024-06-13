#include <stdio.h>

int main(void)
{
    int *iptr;
    int ival = 255;
    iptr = &ival;

    // Wert ausgeben
    printf("*iptr  : %d\n", *iptr);
    printf(" ival  : %d\n", ival);

    // ival neuen Wert zuweisen
    *iptr = 128;

    // Wert ausgeben
    printf("*iptr  : %d\n", *iptr);
    printf(" ival  : %d\n", ival);

    return 0;
}

