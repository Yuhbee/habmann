// Modul2 /lokale_variablen.c
#include <stdio.h>

int main(void)
{
    int ival = 123;
    int *pIval = &ival; // Pointer auf die äußere ival-Variable
    printf("ival: %d\n", ival); // Ausgabe: 123

    { // Neuer Anweisungsblock
        ival = 321;
        printf("ival: %d\n", ival); // Ausgabe: 321
    }
    printf("ival: %d\n", ival); // Ausgabe: 321

    { // Neuer Anweisungsblock
        int ival = 456; // Diese Variable überschattet die äußere Variable 'ival'
        printf("ival: %d\n", ival); // Ausgabe: 456
        printf("*pIval: %d\n", *pIval); // Zugriff auf die äußere Variable 'ival', Ausgabe: 321
    }
    printf("ival: %d\n", ival); // Ausgabe: 321

    return 0;
}

