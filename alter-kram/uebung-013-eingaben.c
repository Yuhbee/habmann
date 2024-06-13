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
//     fgets()                                                               *
//                                                                           *
//****************************************************************************
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
  char third[16] = "Third";
  char str[16];
  char second[16] = "Second";
  printf("\n Enter String: ");
  fgets(str, 16, stdin);
 
  printf( "Eingabe: %x - %.16s\n", (unsigned int)str, str );
  printf( "Second : %x - %.16s\n", (unsigned int)second, second );
  printf( "Third  : %x - %.16s\n", (unsigned int)third, third  );
  return EXIT_SUCCESS;
}


//// Hier beginnt das Hauptprogramm
//int main() {
//
//    // Variablendeklaration
//
//    // Variableninitialisierung
//    char eingabe = 0;
//
//    // Entgegennahme einer Zahl von Anwender
//    printf("\n Bitte gib mir ein Zeichen: ");
//    eingabe = getchar();
//
//    // Anzeige am Bildschirm
//    printf("\n Dein Zeichen lautet: %c\n\n",eingabe);
//
//    // Rückgabe des Wertes 0 an das Betriessystem
//    return 0;
//    }
