#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Variablendeklaration
    int iEingabe;
    unsigned long long int liAusgabe;     
    unsigned long long int liZwischenSumme;

    // Bildschirm löschen
    system("clear");

    // Bildschirmausgabe
    printf("\n\n Das Programm nimmt von Anwender eine Zahl entgegen.\n");
    printf(" Fuer diese Zahl wird dann die Fakultaet berechnet und ausgegeben.\n\n");

    // Eingabe einer Zahl
    printf(" Bitte geben sie eine Ganzzahl (1 bis 63) ein: ");
    scanf(" %i", &iEingabe);

    // Schleife: von 1 bis zum Wert von iEingabe
    //  Da eine Multiplikation mit 0, immer 0 ist:
    liZwischenSumme = 1;
    for (int i = 1; i <= iEingabe; i++)
    {
        liZwischenSumme = liZwischenSumme * i;
    }

    // Ausgabe des Ergebnisses
    liAusgabe = liZwischenSumme;
    printf("\n\n Die Fakultaet von %i ist: %llu", iEingabe, liAusgabe);
    printf("\n\n");

    return 0;
}

