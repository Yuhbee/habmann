#include <stdio.h>

int main()
{
    /* Variableninitialisierung */
    char sBuchstabenSuppe[] = "Auto";

    /* Ausgabe der "Zeichenkette" */
    printf(" In der sBuchstabenSuppe ist gespeichert: %s \n", sBuchstabenSuppe );

    /* Ausgabe der einelnen Felder des Zeichenketten-Array's */
    printf("Das erste  Zeichen in sBuchstabenSuppe ist ein: %c \n", sBuchstabenSuppe[0]);
    printf("Das zweite Zeichen in sBuchstabenSuppe ist ein: %c \n", sBuchstabenSuppe[1]);
    printf("Das dritte Zeichen in sBuchstabenSuppe ist ein: %c \n", sBuchstabenSuppe[2]);
    printf("Das vierte Zeichen in sBuchstabenSuppe ist ein: %c \n", sBuchstabenSuppe[3]);


    return 0;
}
