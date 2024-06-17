#include <stdio.h>
#include <string.h>

// Vorwaertsdeklaration der Funktionen
int vergleicheIntArrays(int aiArray1[], int iGroesse1, int aiArray2[], int iGroesse2);
void druckeIntArray(int aiArray[], int iGroesse);
void druckeCharArray(char acArray[], int iGroesse);
int vergleicheCharArrays(char acArray1[], int iGroesse1, char acArray2[], int iGroesse2);

int main() {
    // Beispiel-Arrays
    int aiArray1[] = {1, 2, 3, 4, 5};
    int aiArray2[] = {1, 2, 3, 4, 5};
    int aiArray3[] = {1, 2, 3, 4, 6};
    int aiArray4[] = {1, 2, 3};

    int iGroesse1 = sizeof(aiArray1) / sizeof(aiArray1[0]);
    int iGroesse2 = sizeof(aiArray2) / sizeof(aiArray2[0]);
    int iGroesse3 = sizeof(aiArray3) / sizeof(aiArray3[0]);
    int iGroesse4 = sizeof(aiArray4) / sizeof(aiArray4[0]);

    // Arrays ausgeben
    printf("Array 1: ");
    druckeIntArray(aiArray1, iGroesse1);

    printf("Array 2: ");
    druckeIntArray(aiArray2, iGroesse2);

    printf("Array 3: ");
    druckeIntArray(aiArray3, iGroesse3);

    printf("Array 4: ");
    druckeIntArray(aiArray4, iGroesse4);

    // Test der Funktion
    int iErgebnis;

    iErgebnis = vergleicheIntArrays(aiArray1, iGroesse1, aiArray2, iGroesse2);
    if (iErgebnis == -1) {
        printf("Array 1 und Array 2 sind gleich.\n");
    } else if (iErgebnis == -2) {
        printf("Array 1 und Array 2 sind ungleich lang.\n");
    } else {
        printf("Array 1 und Array 2 unterscheiden sich an Position %d: %d != %d\n", iErgebnis, aiArray1[iErgebnis], aiArray2[iErgebnis]);
    }

    iErgebnis = vergleicheIntArrays(aiArray1, iGroesse1, aiArray3, iGroesse3);
    if (iErgebnis == -1) {
        printf("Array 1 und Array 3 sind gleich.\n");
    } else if (iErgebnis == -2) {
        printf("Array 1 und Array 3 sind ungleich lang.\n");
    } else {
        printf("Array 1 und Array 3 unterscheiden sich an Position %d: %d != %d\n", iErgebnis, aiArray1[iErgebnis], aiArray3[iErgebnis]);
    }

    iErgebnis = vergleicheIntArrays(aiArray1, iGroesse1, aiArray4, iGroesse4);
    if (iErgebnis == -1) {
        printf("Array 1 und Array 4 sind gleich.\n");
    } else if (iErgebnis == -2) {
        printf("Array 1 und Array 4 sind ungleich lang.\n");
    } else {
        printf("Array 1 und Array 4 unterscheiden sich an Position %d: %d != %d\n", iErgebnis, aiArray1[iErgebnis], aiArray4[iErgebnis]);
    }

    // Beispiel-Arrays fuer Zeichenketten
    char acArray1[] = "Hallo";
    char acArray2[] = "Hallo";
    char acArray3[] = "Halli";
    char acArray4[] = "Hallo Welt";

    int iGroesseC1 = strlen(acArray1);
    int iGroesseC2 = strlen(acArray2);
    int iGroesseC3 = strlen(acArray3);
    int iGroesseC4 = strlen(acArray4);

    // Zeichenketten-Arrays ausgeben
    printf("Zeichenkette 1: ");
    druckeCharArray(acArray1, iGroesseC1);

    printf("Zeichenkette 2: ");
    druckeCharArray(acArray2, iGroesseC2);

    printf("Zeichenkette 3: ");
    druckeCharArray(acArray3, iGroesseC3);

    printf("Zeichenkette 4: ");
    druckeCharArray(acArray4, iGroesseC4);

    // Test der Funktion fuer Zeichenketten
    iErgebnis = vergleicheCharArrays(acArray1, iGroesseC1, acArray2, iGroesseC2);
    if (iErgebnis == -1) {
        printf("Zeichenkette 1 und Zeichenkette 2 sind gleich.\n");
    } else if (iErgebnis == -2) {
        printf("Zeichenkette 1 und Zeichenkette 2 sind ungleich lang.\n");
    } else {
        printf("Zeichenkette 1 und Zeichenkette 2 unterscheiden sich an Position %d: %c != %c\n", iErgebnis, acArray1[iErgebnis], acArray2[iErgebnis]);
    }

    iErgebnis = vergleicheCharArrays(acArray1, iGroesseC1, acArray3, iGroesseC3);
    if (iErgebnis == -1) {
        printf("Zeichenkette 1 und Zeichenkette 3 sind gleich.\n");
    } else if (iErgebnis == -2) {
        printf("Zeichenkette 1 und Zeichenkette 3 sind ungleich lang.\n");
    } else {
        printf("Zeichenkette 1 und Zeichenkette 3 unterscheiden sich an Position %d: %c != %c\n", iErgebnis, acArray1[iErgebnis], acArray3[iErgebnis]);
    }

    iErgebnis = vergleicheCharArrays(acArray1, iGroesseC1, acArray4, iGroesseC4);
    if (iErgebnis == -1) {
        printf("Zeichenkette 1 und Zeichenkette 4 sind gleich.\n");
    } else if (iErgebnis == -2) {
        printf("Zeichenkette 1 und Zeichenkette 4 sind ungleich lang.\n");
    } else {
        printf("Zeichenkette 1 und Zeichenkette 4 unterscheiden sich an Position %d: %c != %c\n", iErgebnis, acArray1[iErgebnis], acArray4[iErgebnis]);
    }

    return 0;
}

// Funktion, um zwei Arrays zu vergleichen
int vergleicheIntArrays(int aiArray1[], int iGroesse1, int aiArray2[], int iGroesse2) {
    if (iGroesse1 != iGroesse2) {
        return -2; // Arrays sind ungleich lang
    }

    for (int i = 0; i < iGroesse1; i++) {
        if (aiArray1[i] != aiArray2[i]) {
            return i; // Erste Ungleichheit gefunden
        }
    }

    return -1; // Arrays sind gleich
}

// Funktion, um ein Array auszugeben
void druckeIntArray(int aiArray[], int iGroesse) {
    printf("[");
    for (int i = 0; i < iGroesse; i++) {
        printf("%d", aiArray[i]);
        if (i < iGroesse - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Funktion, um zwei char-Arrays zu vergleichen
int vergleicheCharArrays(char acArray1[], int iGroesse1, char acArray2[], int iGroesse2) {
    if (iGroesse1 != iGroesse2) {
        return -2; // Arrays sind ungleich lang
    }

    for (int i = 0; i < iGroesse1; i++) {
        if (acArray1[i] != acArray2[i]) {
            return i; // Erste Ungleichheit gefunden
        }
    }

    return -1; // Arrays sind gleich
}

// Funktion, um ein char-Array auszugeben
void druckeCharArray(char acArray[], int iGroesse) {
    printf("[");
    for (int i = 0; i < iGroesse; i++) {
        printf("%c", acArray[i]);
        if (i < iGroesse - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

