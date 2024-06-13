#include <stdio.h>

/* Hier beginnt das Hauptprogramm */
int main()
{
    /* Variablendeklaration */
    /* Datentyp "char" hat einen Speicherbedarf von 8 Bit = 1 Byte */
    char cBuchstabe;

    /* Zuweisung eines Wertes */
    cBuchstabe = 'A'; 


    /* Bildschirmausgabe der Variablen */
    printf("%c", cBuchstabe);
    printf("\n");

    /* Der Variablen einen neuen Wert zuweisen */
    printf("--------------------------\n");
    printf("%c", cBuchstabe);
    cBuchstabe = 'f';
    printf("%c", cBuchstabe);
    printf("%c", cBuchstabe);
    cBuchstabe = 'e';
    printf("%c", cBuchstabe);
    printf("\n");


    /* Rueckgabe eines Wertes an das Betriebssystem */
    return 0;

    }
