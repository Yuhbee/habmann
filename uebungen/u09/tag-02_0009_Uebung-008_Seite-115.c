#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Variablendeklaration
    double dblAnfangsBetrag, dblZinssatz;
    int iJahre;

    system("clear"); // Bildschirm loeschen

    // Eingabe des Anfangsbetrags
    printf("\n\n Bitte geben Sie den Anfangsbetrag ein: ");
    scanf("%lf", &dblAnfangsBetrag);

    // Eingabe des Zinssatzes
    printf(" Bitte geben Sie den Zinssatz ein (in Prozent): ");
    scanf("%lf", &dblZinssatz);
    dblZinssatz = dblZinssatz / 100; // Umwandlung in Dezimalform

    // Eingabe der Anzahl der Jahre
    printf(" Bitte geben Sie die Anzahl der Jahre ein: ");
    scanf("%d", &iJahre);

    // Berechnung und Ausgabe des Betrags für jedes Jahr
    double dblBetrag = dblAnfangsBetrag;
    printf("\n"); // Leerzeile einfuegen
    for (int i = 1; i <= iJahre; i++) {
        dblBetrag = dblBetrag + (dblBetrag * dblZinssatz);
        printf(" Nach Jahr %d: %.2lf\n", i, dblBetrag);
    }
    printf("\n\n"); // Leerzeilen einfuegen

    return 0;
}


