#include <stdio.h>

int main(void) {
    int anfangswert = 123;
    int *zeigerAufAnfangswert = &anfangswert; // Zeiger auf die Variable anfangswert

    // Anzeige des Werts der Variable anfangswert
    printf("anfangswert: %d\n", anfangswert);

    // Anzeige der Speicheradresse von anfangswert
    printf("Adresse von anfangswert: %p\n", (void*)&anfangswert);

    // Anzeige der Speicheradresse, auf die der Zeiger zeigt
    printf("Adresse, auf die zeigerAufAnfangswert zeigt: %p\n", (void*)zeigerAufAnfangswert);

    // Anzeige des Werts, auf den der Zeiger zeigt
    printf("Wert, auf den zeigerAufAnfangswert zeigt: %d\n", *zeigerAufAnfangswert);

    return 0;
}

