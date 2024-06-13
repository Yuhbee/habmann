#include <stdio.h>   // Fuer printf und scanf
#include <stdlib.h>  // Fuer die system-Funktion

int main() {
    double num1, num2;  // Variablen zur Speicherung der eingegebenen Zahlen
    char operation;     // Variable zur Speicherung der ausgewaerhlten Operation
    double result;      // Variable zur Speicherung des Ergebnisses

    while (1) {
        // Bildschirm loeschen, hier fuer Linux
        system("clear");   // Fuer die Linux-Konsole
        // system("cls");  // Fuer die Windows-Shell

        // Eingabe der ersten Zahl
        printf("Geben Sie die erste Zahl ein: ");
        scanf("%lf", &num1);

        // Eingabe der zweiten Zahl
        printf("Geben Sie die zweite Zahl ein: ");
        scanf("%lf", &num2);

        // Eingabe der gewuenschten Operation
        printf("Waehlen Sie eine Operation (A für Addition, S für Subtraktion, M für Multiplikation, D für Division): ");
        scanf(" %c", &operation);

        // Verarbeitung der Operation basierend auf der Benutzereingabe
        switch (operation) {
            case 'A':  // Addition
            case 'a':
                result = num1 + num2;  // Addiere die beiden Zahlen
                printf("Ergebnis: %.2lf\n", result);  // Ausgabe des Ergebnisses
                break;
            case 'S':  // Subtraktion
            case 's':
                result = num1 - num2;  // Subtrahiere die zweite Zahl von der ersten
                printf("Ergebnis: %.2lf\n", result);  // Ausgabe des Ergebnisses
                break;
            case 'M':  // Multiplikation
            case 'm':
                result = num1 * num2;  // Multipliziere die beiden Zahlen
                printf("Ergebnis: %.2lf\n", result);  // Ausgabe des Ergebnisses
                break;
            case 'D':  // Division
            case 'd':
                if (num2 != 0) {  // Ueberprüfe, ob die zweite Zahl nicht null ist
                    result = num1 / num2;  // Dividiere die erste Zahl durch die zweite
                    printf("Ergebnis: %.2lf\n", result);  // Ausgabe des Ergebnisses
                } else {
                    printf("Fehler: Division durch 0 ist nicht erlaubt.\n");  // Fehlermeldung bei Division durch null
                }
                break;
            default:
                printf("Ungueltige Operation.\n");  // Fehlermeldung bei ungueltiger Operation
                break;
        }

        // Abfrage, ob eine weitere Berechnung durchgeführt werden soll
        char weiter;
        printf("Moechten Sie eine weitere Berechnung durchfuehren? (J/N): ");
        scanf(" %c", &weiter);
        
        // Ueberpruefe, ob der Benutzer das Programm beenden moechte
        if (weiter == 'N' || weiter == 'n') {
            break;  // Beende die Schleife und damit das Programm
        }
    }

    return 0;  // Rueckgabe 0 signalisiert erfolgreiche Ausfuehrung
}

