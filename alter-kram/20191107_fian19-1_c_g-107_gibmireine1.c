#include <stdio.h>
#include <limits.h>

int main()
{
    /* Variablendeklaration */
    /* der Datentyp 'int' ist eine Ganzzahl */ 
    char      cZahl;
    short     iZahl_short_int;
    int       iZahl_int;
    long      iZahl_long_int;
    long long iZahl_long_long_int;

    /* Variablenzuweisung */
    cZahl               = 127;
    iZahl_short_int     = 32766;
    iZahl_int           = 65535;
    iZahl_long_int      = 65535;
    iZahl_long_long_int = 65535;

    /* Variable am Bildschirm ausgeben */
    printf(" ------------------------------------------------------------------\n");
    printf("Die Variable mit dem Namen iZahl_short_int lautet: %d\n",       iZahl_short_int);
    printf("Die Variable mit dem Namen iZahl_int lautet: %d\n",             iZahl_int);
    printf("Die Variable mit dem Namen iZahl_long_int lautet: %ld\n",       iZahl_long_int);
    printf("Die Variable mit dem Namen iZahl_long_long_int lautet: %lld\n", iZahl_long_long_int);

    /* So wird der Speicherbedarf angezeit */
    printf(" ------------------------------------------------------------------\n");
    printf(" Der Datentyp          char benötigt %ld Bit's als Speicherbedarf!\n", sizeof(char) * 8 ); 
    printf(" Der Datentyp     short int benötigt %ld Bit's als Speicherbedarf!\n", sizeof(short int) * 8 ); 
    printf(" Der Datentyp           int benötigt %ld Bit's als Speicherbedarf!\n", sizeof(int) * 8 ); 
    printf(" Der Datentyp      long int benötigt %ld Bit's als Speicherbedarf!\n", sizeof(long int) * 8 ); 
    printf(" Der Datentyp long long int benötigt %ld Bit's als Speicherbedarf!\n", sizeof(long long int) * 8 ); 

    printf(" ------------------------------------------------------------------\n");
    printf(" Das Maximum von \"int\" ist auf diesem System: %d \n", INT_MAX);
    printf(" Das Minimum von \"int\" ist auf diesem System: %d \n", INT_MIN);
    printf(" Das Maximum von \"long\" ist auf diesem System: %ld \n", LONG_MAX);
    printf(" Das Minimum von \"long\" ist auf diesem System: %ld \n", LONG_MIN);
    printf(" Das Maximum von \"long long\" ist auf diesem System: %lld \n", LLONG_MAX);
    printf(" Das Minimum von \"long long\" ist auf diesem System: %lld \n", LLONG_MIN);

    printf("\n");
    return 0;    
}
