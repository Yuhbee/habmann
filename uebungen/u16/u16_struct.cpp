#include <iostream>
#include <vector>   // Notwendig für std::vector
#include <string>   // Notwendig für std::string

// Definition der Struktur 'person'
struct SPerson {
    std::string strVorname;   // Vorname der Person
    std::string strNachname;  // Nachname der Person
    int iGeburtsTag;          // Geburtsdatum - Tag
    int iGeburtsMonat;        // Geburtsdatum - Monat
    int iGeburtsJahr;         // Geburtsdatum - Jahr
};

int main() {
    // Definiere einen Vektor, der mehrere Elemente der Struktur 'SPerson' speichert
    std::vector<SPerson> vecPersonen(10);  // Initialisiert mit 10 Elementen

    // Fülle das erste Element exemplarisch
    vecPersonen[0].strVorname = "Michelangelo";
    vecPersonen[0].strNachname = "Bounarroti";
    vecPersonen[0].iGeburtsTag = 6;
    vecPersonen[0].iGeburtsMonat = 3;
    vecPersonen[0].iGeburtsJahr = 1475;

    // Ausgabe des ersten Elements zur Kontrolle
    std::cout << "Vorname: " << vecPersonen[0].strVorname << std::endl;
    std::cout << "Nachname: " << vecPersonen[0].strNachname << std::endl;
    std::cout << "Geburtsdatum: " << vecPersonen[0].iGeburtsTag << "."
              << vecPersonen[0].iGeburtsMonat << "."
              << vecPersonen[0].iGeburtsJahr << std::endl;

    return 0;
}