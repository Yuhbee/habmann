//****************************************************************************
//   Programmname ..........: uebung-013a-eingaben.c                         *
//   Version: ..............: 1.0                                            *
//                                                                           *
//****************************************************************************
//   Autor .................: U. Bauermann                                   *
//   Erstellungsdatum: .....: 20180208                                       *
//   Uebung: ...............: Uebung_013a                                    *
//                                                                           *
//   Aenderungshistorie.....:                                                *
//   20180208: .............:                                                *
//                                                                           *
//****************************************************************************
//   Beschreibung:                                                           *
//     Eingaben                                                              *
//     scanf()                                                               *
//                                                                           *
//****************************************************************************
#include<stdio.h>

// Hier beginnt das Hauptprogramm
int main() {

    // Variableninitialisierung
    int eingabe = 0;
    char zeichenkette[16];

    // Entgegennahme einer Zahl vom Anwender
    printf("\n Bitte gib mir eine Zahl: ");
    scanf("%d",&eingabe);

    // Entgegennahme einer Zeichenkette vom Anwender
    printf("\n Bitte gib mir eine Zeichenkette: ");
    scanf("%s",&zeichenkette);

    // Anzeige am Bildschirm
    printf("\n Deine Eingabezahl lautet: %d\n\n",eingabe);
    printf("\n Deine Zeichenkette lautet: %s\n\n",zeichenkette);

    // Rückgabe des Wertes 0 an das Betriessystem
    return 0;
    }
