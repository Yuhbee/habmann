//****************************************************************************
//   Programmname ..........: uebung-13b-eingaben.c                          *
//   Version: ..............: 1.0                                            *
//                                                                           *
//****************************************************************************
//   Autor .................: U. Bauermann                                   *
//   Erstellungsdatum: .....: 20180207                                       *
//   Uebung: ...............: Uebung_013                                     *
//                                                                           *
//   Aenderungshistorie.....:                                                *
//   20180206: .............:                                                *
//                                                                           *
//****************************************************************************
//   Beschreibung:                                                           *
//     Eingaben                                                              *
//     getchar(), gets()                                            *
//                                                                           *
//****************************************************************************
#include<stdio.h>

// Hier beginnt das Hauptprogramm
int main() {

    // Variablendeklaration

    // Variableninitialisierung
    char eingabe = 0;

    // Entgegennahme einer Zahl von Anwender
    printf("\n Bitte gib mir ein Zeichen: ");
    eingabe = getchar();

    // Anzeige am Bildschirm
    printf("\n Dein Zeichen lautet: %c\n\n",eingabe);

    // Rückgabe des Wertes 0 an das Betriessystem
    return 0;
    }
