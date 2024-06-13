#include <stdio.h>
#include <math.h> // Für die pow-Funktion

int main(void) {
    // Variablendeklaration
    double dblAnfangsBetrag, dblZinssatz;
    int iJahre;
    
    // Eingabe des Anfangsbetrags
    printf("Bitte geben Sie den Anfangsbetrag ein: ");
    scanf("%lf", &dblAnfangsBetrag);

    // Eingabe des Zinssatzes
    printf("Bitte geben Sie den Zinssatz ein (in Prozent): ");
    scanf("%lf", &dblZinssatz);
    dblZinssatz = dblZinssatz / 100; // Umwandlung in Dezimalform

    // Eingabe der Anzahl der Jahre
    printf("Bitte geben Sie die Anzahl der Jahre ein: ");
    scanf("%d", &iJahre);

    // Berechnung und Ausgabe des Betrags für jedes Jahr
    double dblBetrag;
    for (int i = 1; i <= iJahre; i++) {
        dblBetrag = dblAnfangsBetrag * pow(1 + dblZinssatz, i);
        printf("Nach Jahr %d: %.2lf\n", i, dblBetrag);
    }

    return 0;
}

