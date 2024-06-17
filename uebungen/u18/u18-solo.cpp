#include <iostream>
#include <string>

class Konto {
private:
    long stand;
    std::string name;

public:
    // Default-Konstruktor
    Konto(){}

    // Benutzerdefinierter Konstruktor ohne Argumente
    //Konto() : stand(0), name("Unbekannt") {}

    // Parametrisierter Konstruktor (Elementarkonstruktor)
    Konto(long s, std::string n) : stand(s), name(n) {}

    // Getter und Setter für den Kontostand
    long get_stand() {
        return stand;
    }

    void set_stand(long s) {
        stand = s;
    }

    // Getter und Setter für den Namen
    std::string get_name() {
        return name;
    }

    void set_name(std::string n) {
        name = n;
    }

    // Funktion zum Drucken der Kontoinformationen
    void print() {
        std::cout << "Kontoinhaber: " << name << std::endl;
        std::cout << "Kontostand: " << stand << std::endl;
    }
};

int main() {
    // Standardkonstruktor verwenden
    Konto meinKonto;
    meinKonto.set_name("Lara Blanco");
    meinKonto.set_stand(0);
    
    // Kontoinformationen mit der neuen print-Methode ausgeben
    meinKonto.print();

    // Parametrisierten Konstruktor verwenden
    Konto einWeiteresKonto(1001, "Aladin Wunderlampe");
    
    // Kontoinformationen mit der neuen print-Methode ausgeben
    einWeiteresKonto.print();

    return 0;
}
