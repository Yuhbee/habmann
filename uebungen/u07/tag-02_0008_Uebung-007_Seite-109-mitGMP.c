#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main(void)
{
    // Variablendeklaration
    int iEingabe;
    mpz_t liAusgabe;     
    mpz_t liZwischenSumme;

    // Initialisiere die großen Zahlen
    mpz_init(liAusgabe);
    mpz_init(liZwischenSumme);

    // Bildschirm löschen
    system("clear");

    // Bildschirmausgabe
    printf("\n\n Das Programm nimmt von Anwender eine Zahl entgegen.\n");
    printf(" Fuer diese Zahl wird dann die Fakultaet berechnet und ausgegeben.\n\n");

    // Eingabe einer Zahl
    printf(" Bitte geben sie eine Ganzzahl (1 bis 63) ein: ");
    scanf("%d", &iEingabe);

    // Schleife: von 1 bis zum Wert von iEingabe
    //  Da eine Multiplikation mit 0, immer 0 ist:
    mpz_set_ui(liZwischenSumme, 1); // Setze liZwischenSumme auf 1
    for (int i = 1; i <= iEingabe; i++)
    {
        mpz_mul_ui(liZwischenSumme, liZwischenSumme, i); // liZwischenSumme = liZwischenSumme * i
    }

    // Ausgabe des Ergebnisses
    mpz_set(liAusgabe, liZwischenSumme);
    printf("\n\n Die Fakultaet von %d ist: ", iEingabe);
    mpz_out_str(stdout, 10, liAusgabe); // Ausgabe der großen Zahl
    printf("\n\n");

    // Speicher freigeben
    mpz_clear(liAusgabe);
    mpz_clear(liZwischenSumme);

    return 0;
}

