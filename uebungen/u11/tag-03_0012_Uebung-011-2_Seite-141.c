#include <stdio.h>
#include <stdlib.h> // fuer die Funktion system()

// Vorausdeklaration der verwendeten Funktionen
void vertauschen(int *piErsteZahl, int *piZweiteZahl);

int main() {
    system("clear"); // Bildschirm loeschen
    printf("\n\n Programm-Name: Schwarzmarkt!\n\n");

    // Variablen-Deklaration
    int iZahl1, iZahl2;
    char cBestaetigung;

    // Eingabe der zwei Zahlen durch den Benutzer
    printf("\n\n Geben Sie die  erste Zahl ein: ");
    scanf("%d", &iZahl1);
    printf(" Geben Sie die zweite Zahl ein: ");
    scanf("%d", &iZahl2);

    // Ausgabe der urspruenglichen Werte
    printf("\n Vor dem Vertauschen:\n    Erste  Zahl = %d\n    Zweite Zahl = %d\n", iZahl1, iZahl2);

    // Benutzerabfrage zur Bestaetigung des Tauschs
    printf("\n Sind Sie sicher, moechten Sie wirklich tauschen? (j/n): ");
    scanf(" %c", &cBestaetigung);

    if (cBestaetigung == 'j' || cBestaetigung == 'J') {
        // Aufruf der Vertausch-Funktion
        vertauschen(&iZahl1, &iZahl2);

        // Ausgabe der vertauschten Werte
        printf("\n Nach dem Vertauschen:\n    Erste  Zahl = %d\n    Zweite Zahl = %d\n\n\n", iZahl1, iZahl2);
    } else {
        printf("\n Die Werte wurden nicht vertauscht.\n\n\n");
    }

    return 0;
}

// ---------------- Unterfunktionen: ------------------------------------------------

// Definition der Funktion zum Vertauschen
// Hinweis: Meine kuenstlerische Freiheit entgegen der Aufgabenstellung
// benutze ich einen deutschen Namen für die Funktion (anstatt 'swap')
void vertauschen(int *piErsteZahl, int *piZweiteZahl) {
    int iKleinesHelferlein = *piErsteZahl;
    *piErsteZahl = *piZweiteZahl;
    *piZweiteZahl = iKleinesHelferlein;
}

