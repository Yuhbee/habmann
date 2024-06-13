#include <iostream>
#include <array>    // Notwendig für std::array
#include <string>   // Notwendig für std::string

// Definition der Struktur 'SPerson'
struct SPerson {
    std::string strVorname;   // Vorname der Person
    std::string strNachname;  // Nachname der Person
    int iGeburtsTag;          // Geburtsdatum - Tag
    int iGeburtsMonat;        // Geburtsdatum - Monat
    int iGeburtsJahr;         // Geburtsdatum - Jahr
};

// Funktion zum Fuellen eines SPerson-Elements
void FuegePersonHinzu(std::array<SPerson, 10>& arrPersonen, int index, const std::string& strVorname, const std::string& strNachname, int iTag, int iMonat, int iJahr) {
    if (index >= 0 && index < arrPersonen.size()) {
        arrPersonen[index].strVorname = strVorname;
        arrPersonen[index].strNachname = strNachname;
        arrPersonen[index].iGeburtsTag = iTag;
        arrPersonen[index].iGeburtsMonat = iMonat;
        arrPersonen[index].iGeburtsJahr = iJahr;
    } else {
        std::cerr << "Index außerhalb des gültigen Bereichs!" << std::endl;
    }
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
    std::array<SPerson, 10> arrPersonen;

    // Fuelle das erste Element exemplarisch
    FuegePersonHinzu(arrPersonen, 0, "Michelangelo", "Buonarroti", 3, 6, 1475);

    // Ausgabe des ersten Elements zur Kontrolle
    GibPersonAus(arrPersonen[0]);

    return 0;
}
