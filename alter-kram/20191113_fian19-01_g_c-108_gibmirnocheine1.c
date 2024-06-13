#include <stdio.h>
#include <limits.h>

int main()
{
    /* Variablendeklaration */
    /* der Datentyp 'unsigned int' ist eine nicht-negative Ganzzahl */
    /* Hinweis: Der Speicherplatz kann sich je nach Implementation verschieben! */
    unsigned char      iZahl_unsigned;                   /* Eine Integer-Zahl im Bereich  "8-Bit"-Speicherplatz */
    unsigned short     iZahl_unsigned_short_int;         /* Eine Integer-Zahl im Bereich  "16-Bit"-Speicherplatz */
    unsigned int       iZahl_unsigned_int;               /* Eine Integer-Zahl im Bereich  "16-Bit"-Speicherplatz */
    unsigned long      iZahl_unsigned_long_int;          /* Eine Integer-Zahl im Bereich  "64-Bit"-Speicherplatz */
    unsigned long long iZahl_unsigned_long_long_int;     /* Eine Integer-Zahl im Bereich  "64-Bit"-Speicherplatz */
    unsigned char      iMinimum_unsigned;                /* Der Kleinste moegliche unsigned int Wert */

    /* Variablenzuweisung */
    iZahl_unsigned               = 127;     /* Eine Zufalls-Zahl im Bereich  "8-Bit"-Speicherplatz */
    iZahl_unsigned_short_int     = 32766;   /* Eine Zufalls-Zahl im Bereich "16-Bit"-Speicherplatz */
    iZahl_unsigned_int           = 65535;   /* Eine Zufalls-Zahl im Bereich "16-Bit"-Speicherplatz */
    iZahl_unsigned_long_int      = 65535;   /* Eine Zufalls-Zahl im Bereich "64-Bit"-Speicherplatz */
    iZahl_unsigned_long_long_int = 65535;   /* Eine Zufalls-Zahl im Bereich "64-Bit"-Speicherplatz */
    iMinimum_unsigned            = 0;       /* Der KLeinste moegliche unsigned Wert ist Null       */

    /* Variable am Bildschirm ausgeben */
    printf(" ------------------------------------------------------------------\n");
    printf(" Die Variable mit dem Namen iZahl_unsigned %d\n",                         iZahl_unsigned);
    printf(" Die Variable mit dem Namen iZahl_unsigned_short_int lautet: %d\n",       iZahl_unsigned_short_int);
    printf(" Die Variable mit dem Namen iZahl_unsigned_int lautet: %d\n",             iZahl_unsigned_int);
    printf(" Die Variable mit dem Namen iZahl_unsigned_long_int lautet: %ld\n",       iZahl_unsigned_long_int);
    printf(" Die Variable mit dem Namen iZahl_unsigned_long_long_int lautet: %lld\n", iZahl_unsigned_long_long_int);

    /* So wird der Speicherbedarf der C-Implementierung angezeit */
    printf(" ------------------------------------------------------------------\n");
    printf(" Der Datentyp          char benötigt %ld Bit's als Speicherbedarf!\n", sizeof(char) * 8 );
    printf(" Der Datentyp     short int benötigt %ld Bit's als Speicherbedarf!\n", sizeof(short int) * 8 );
    printf(" Der Datentyp           int benötigt %ld Bit's als Speicherbedarf!\n", sizeof(int) * 8 );
    printf(" Der Datentyp      long int benötigt %ld Bit's als Speicherbedarf!\n", sizeof(long int) * 8 );
    printf(" Der Datentyp long long int benötigt %ld Bit's als Speicherbedarf!\n", sizeof(long long int) * 8 );

    /* Ausgabe der Konstanten der C-Implementierung */
    printf(" ------------------------------------------------------------------\n");
    printf(" Das Minimum von \"unsigned char\" ist auf diesem System: %d \n", iMinimum_unsigned);
    printf(" Das Maximum von \"unsigned char\" ist auf diesem System: %u \n", UCHAR_MAX);
    printf(" Das Minimum von \"unsigned short int\" ist auf diesem System: %d \n", iMinimum_unsigned);
    printf(" Das Maximum von \"unsigned short int\" ist auf diesem System: %u \n", USHRT_MAX);
    printf(" Das Minimum von \"unsigned int\" ist auf diesem System: %d \n", iMinimum_unsigned);
    printf(" Das Maximum von \"unsigned int\" ist auf diesem System: %u \n", UINT_MAX);
    printf(" Das Minimum von \"unsigned long\" ist auf diesem System: %d \n", iMinimum_unsigned);
    printf(" Das Maximum von \"unsigned long\" ist auf diesem System: %lu \n", ULONG_MAX);
    printf(" Das Minimum von \"unsigned long long\" ist auf diesem System: %d \n", iMinimum_unsigned);
    printf(" Das Maximum von \"unsigned long long\" ist auf diesem System: %llu \n", ULLONG_MAX);

    printf("\n");    /* Ausgabe einer letzten Zeilenschaltung */
    return 0;        /* Integer-Rueckgabe an das Betriebssystem */
}
