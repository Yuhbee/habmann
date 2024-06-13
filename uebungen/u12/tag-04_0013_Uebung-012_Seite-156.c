#include <stdio.h>
#include <stdlib.h>

// Funktion, um das Maximum in einem Array zu finden
int findeMax(int aiZahlen[], int iGroesse) {
    int iMax = aiZahlen[0];
    for (int i = 1; i < iGroesse; i++) {
        if (aiZahlen[i] > iMax) {
            iMax = aiZahlen[i];
        }
    }
    return iMax;
}

// Funktion, um das Array auszugeben
void druckeArray(int aiZahlen[], int iGroesse) {
    printf("\n\n Array-Inhalt: [");
    for (int i = 0; i < iGroesse; i++) {
        printf("%d", aiZahlen[i]);
        if (i < iGroesse - 1) {
            printf(", ");
        }
    }
    printf("]\n\n");
}

int main() {
    system("clear"); // Bildschirm loeschen

    // Beispiel-Array
    int aiZahlen[] = {3, 5, 7, 2, 8, 6, 4, 7, 9, 1};
    int iGroesse = sizeof(aiZahlen) / sizeof(aiZahlen[0]);

    // Array-Inhalt ausgeben
    druckeArray(aiZahlen, iGroesse);

    // Maximalwert des Arrays finden
    int iMax = findeMax(aiZahlen, iGroesse);

    // Maximalwert ausgeben
    printf(" Der Maximalwert im Array ist: %d\n\n\n", iMax);

    return 0;
}

