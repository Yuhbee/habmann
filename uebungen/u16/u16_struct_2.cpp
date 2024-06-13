#include <iostream>
#include <string>

// Definition der Struktur 'SPerson'
struct SPerson {
    std::string strVorname;   // Vorname der Person
    std::string strNachname;  // Nachname der Person
    int iGeburtsTag;          // Geburtsdatum - Tag
    int iGeburtsMonat;        // Geburtsdatum - Monat
    int iGeburtsJahr;         // Geburtsdatum - Jahr
};

// Funktion zum Füllen eines SPerson-Elements
SPerson ErstellePerson(const std::string& strVorname, const std::string& strNachname, int iTag, int iMonat, int iJahr) {
    SPerson person;
    person.strVorname = strVorname;
    person.strNachname = strNachname;
    person.iGeburtsTag = iTag;
    person.iGeburtsMonat = iMonat;
    person.iGeburtsJahr = iJahr;
    return person;
}

// Funktion zur Ausgabe eines SPerson-Elements
void GibPersonAus(const SPerson& person) {
    std::cout << "Vorname: " << person.strVorname << std::endl;
    std::cout << "Nachname: " << person.strNachname << std::endl;
    std::cout << "Geburtsdatum: " << person.iGeburtsTag << "."
              << person.iGeburtsMonat << "."
              << person.iGeburtsJahr << std::endl;
}

int main() {
    // Definiere ein Array, das 10 Elemente der Struktur 'SPerson' speichert
    SPerson arrPersonen[10];

    // Fuelle das erste Element exemplarisch
    arrPersonen[0] = ErstellePerson("Michelangelo", "Bounarroti", 6, 3, 1475);

    // Ausgabe des ersten Elements zur Kontrolle
    GibPersonAus(arrPersonen[0]);

    return 0;
}
