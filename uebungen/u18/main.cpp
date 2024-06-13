#include <iostream>
#include "konto.h"

int main() {
    // Standardkonstruktor verwenden
    Konto meinKonto;
    meinKonto.set_name("Lara Loft");
    meinKonto.set_stand(0);
    
    // Kontoinformationen mit der neuen print-Methode ausgeben
    meinKonto.print();

    // Parametrisierten Konstruktor verwenden
    Konto einWeiteresKonto(1001, "Aladin Wunderlampe");
    
    // Kontoinformationen mit der neuen print-Methode ausgeben
    einWeiteresKonto.print();

    return 0;
}
