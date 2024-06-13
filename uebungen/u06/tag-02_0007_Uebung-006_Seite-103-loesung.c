#include <stdio.h>

int main(void) {

  // Initialisierung der Variablen work
  int work = 0;

  // Ausgabe eines Menues fuer den Benutzer
  printf("-1- PC 1 hochfahren\n");
  printf("-2- PC 2 hochfahren\n");
  printf("-3- Drucker einschalten\n");
  printf("-4- Kaffee machen\n");
  printf("-5- Feierabend machen\n");
  printf("Was wollen Sie tun: ");

  // Die Bedingung ueberprueft ob eine Eingabe erfolgreich ist:
  //  Info: die Funktion scanf() gibt einen Rückgabewert aus
  //  Wenn die Eingabe erflogreich wqar wird der Wert 1 zurueckgegeben.
  // Die Eingabe wird in der Variablen work gespeichert
  if (scanf("%d", &work) != 1) {
    // Die Eingabe war nicht erfolgreich
    // Ausgabe einer Fehlermeldung
    printf("Fehler bei der Eingabe...\n");
    // Das Programm wird terminiert
    return 1;
  }

  switch (work) {
    case 1:
      // Ja, es wurde eine 1 eingegben:
      printf("PC 1 wird hochgefahren\n"); //  Bildschirmausgabe
      break;  //  mache nach der switch-case Abfrage weiter
    case 2:   // Wurde eine 1 eingegben?:
      printf("PC 2 wird hochgefahren\n");
      break;
    case 3:
      printf("Drucker wird eingeschaltet\n");
      break;
    case 4:
      printf("Kaffee wird gemacht\n");
      break;
    case 5:
      printf("Gute Nacht\n");
      break;
    default:
      printf("Falsche Eingabe!\n");
  }

  return 0;
}

