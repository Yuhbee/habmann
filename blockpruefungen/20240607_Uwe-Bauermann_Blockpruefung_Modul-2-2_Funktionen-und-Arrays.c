#include <stdio.h>
#include <stdlib.h>

// Vorwaertsdeklaration der Funktionen
int iMax(int aiZahlen[], int iAnzahl);
int iMin(int aiZahlen[], int iAnzahl);
long long int iSquare(long long int iZahl);

int main() {
    int aiZahlen[3];
    int i, iMinWert, iMaxWert, iSumme = 0;
    long long int llProdukt = 1;

    system("clear");  // Bildschirm loeschen

    // Benutzereingabe
    printf("\n\n  Bitte geben Sie drei ganze Zahlen ein:\n\n");
    for (i = 0; i < 3; i++) {
        printf("    Zahl %d: ", i + 1);
        scanf("%d", &aiZahlen[i]);
    }

    // Maximum und Minimum berechnen
    iMaxWert = iMax(aiZahlen, 3);
    iMinWert = iMin(aiZahlen, 3);

    // Ausgabe von Maximum und Minimum
    printf("\n\n  Maximum der eingegebenen Zahlen: %d\n", iMaxWert);
    printf("  Minimum der eingegebenen Zahlen: %d\n", iMinWert);

    // Summe und Produkt der Zahlen zwischen Minimum und Maximum (einschließlich)
    // Aus Zeitgruenden (Werkstatt), kein Abfangen von einem Ueberlauf der Variablen: llProdukt
    for (i = iMinWert; i <= iMaxWert; i++) {
        iSumme += i;
        llProdukt *= i;
    }

    // Ausgabe von Summe und Produkt
    printf("\n\n  Summe aller Zahlen zwischen Minimum und Maximum (einschließlich): %d\n", iSumme);
    printf("  Produkt aller Zahlen zwischen Minimum und Maximum (einschließlich): %lld\n\n\n", llProdukt);

    // Quadrat jeder eingegebenen Zahl berechnen und ausgeben
    for (i = 0; i < 3; i++) {
        printf("  Quadrat der Zahl %d: %lld\n", aiZahlen[i], iSquare(aiZahlen[i]));
    }

    printf("\n\n Ende. \n\n");

    return 0;
}

// Funktion zur Berechnung des Maximums eines Arrays
int iMax(int aiZahlen[], int iAnzahl) {
    int iMaxWert = aiZahlen[0];
    for (int i = 1; i < iAnzahl; i++) {
        if (aiZahlen[i] > iMaxWert) {
            iMaxWert = aiZahlen[i];
        }
    }
    return iMaxWert;
}

// Funktion zur Berechnung des Minimums eines Arrays
int iMin(int aiZahlen[], int iAnzahl) {
    int iMinWert = aiZahlen[0];
    for (int i = 1; i < iAnzahl; i++) {
        if (aiZahlen[i] < iMinWert) {
            iMinWert = aiZahlen[i];
        }
    }
    return iMinWert;
}

// Funktion zur Berechnung des Quadrats einer Zahl
long long int iSquare(long long int iZahl) {
    return iZahl * iZahl;
}

