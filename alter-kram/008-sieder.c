 // ***************************************************************************
//                                                                           *
//   Programmname..: 20191112_19sieder_c_g-108_gibmirnocheine1.c             *
//   Auftragsdatum.: 20191112                                                *
//   Auftraggeber..: Bauermann                                               *
//                                                                           *
// ************************************************************************* *
//                                                                           *
//   Autor.................: Vanessa Sieder                                  *
//   Ausbildungsstatus.....: Fian 19, Lehrjahr 1                             *
//   Erstellungsdatum......: 20191112                                        *
//   Letzte Aenderunsdatum.: 20191112                                        *
//   Aufgabe/Uebung........: c_g-108_gibmirnocheine1                         *
//                                                                           *
// ************************************************************************* *
//                                                                           *
//   Beschreibung:                                                           *
//   Verschiedene Variablen werden als unsigned deklariert.                  *
//                                                                           *
//                                                                           *
//									     *
//                                                                           *
//                                                                           *
// ***************************************************************************


#include <stdio.h>
#include <limits.h>
  
int main()
{
    //Variablendeklaration
    //Minimum Wert für unsigned Variablen deklarieren
    int min_unsigned;

    //Der Datentyp 'unsigned' ist eine Ganzzahl, ohne negativer Zahlen
    unsigned char cZahl;					// 8Bit
    unsigned short int iZahl_unsigned_short_int; 		// 16Bit
    unsigned int iZahl_unsigned_int; 				// 32Bit
    unsigned long int iZahl_unsigned_long_int; 			// 32 oder 64Bit
    unsigned long long int iZahl_unsigned_long_long_int; 	// 64Bit

    //Variablenzuweisung
    min_unsigned = 0;

    cZahl = 127;
    iZahl_unsigned_short_int = 32766;
    iZahl_unsigned_int = 65535;
    iZahl_unsigned_long_int = 65535;
    iZahl_unsigned_long_long_int = 65535;

    //Variable ausgeben
    printf("Die Variable cZahl lautet: %d\n", cZahl);
    printf("Die Variable iZahl lautet: %d\n", iZahl_unsigned_int);
    printf("Die Variable iZahl_short_int lautet: %d\n", iZahl_unsigned_short_int);
    printf("Die Variable iZahl_long_int lautet: %d\n", iZahl_unsigned_long_int);
    printf("Die Variable iZahl_long_long_int lautet: %d\n", iZahl_unsigned_long_long_int);

    //So wird der Speicherbedarf angezeigt
    printf("------------------------------------------------------------------------\n");
    printf("Der Datentyp char benoetigt %d Bit's als Speicherbedarf.\n", sizeof(char) * 8);
    printf("Der Datentyp short int benoetigt %d Bit's als Speicherbedarf.\n", sizeof(short int) * 8);
    printf("Der Datentyp int benoetigt %d Bit's als Speicherbedarf.\n", sizeof(int) * 8);
    printf("Der Datentyp long int benoetigt %d Bit's als Speicherbedarf.\n", sizeof(long int) * 8);
    printf("Der Datentyp long long int benoetigt %d Bit's als Speicherbedarf.\n", sizeof(long long int) * 8);

    printf("------------------------------------------------------------------------\n");
    printf("Das Minimum von \"signed char\" ist auf diesem System: %d \n", min_unsigned);
    printf("Das Maximum von \"signed char\" ist auf diesem System: %u \n", UCHAR_MAX);
    printf("Das Minimum von \"signed short int\" ist auf diesem System: %d \n", min_unsigned);
    printf("Das Maximum von \"signed short int\" ist auf diesem System: %u \n", USHRT_MAX);
    printf("Das Minimum von \"signed int\" ist auf diesem System: %d \n", min_unsigned);
    printf("Das Maximum von \"signed int\" ist auf diesem System: %u \n", UINT_MAX);
    printf("Das Minimum von \"signed long\" ist auf diesem System: %ld \n", min_unsigned);
    printf("Das Maximum von \"signed long\" ist auf diesem System: %lu \n", ULONG_MAX);
    printf("Das Minimum von \"signed long long\" ist auf diesem System: %lld \n", min_unsigned);
    printf("Das Maximum von \"signed long long\" ist auf diesem System: %llu \n", ULLONG_MAX);

    return 0;
}
