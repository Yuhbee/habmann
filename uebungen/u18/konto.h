#ifndef KONTO_H
#define KONTO_H

#include <string> // Wichtig für std::string

class Konto
{
private:
    // Attribute der Klasse "Konto"
    long stand;
    std::string name;

public:
    // Standardkonstruktor
    Konto() : stand(0), name("Unbekannt") {}

    // Parametrisierter Konstruktor
    Konto(long s, std::string n) : stand(s), name(n) {}

    // Elementfunktionen der Klasse "Konto"
    long get_stand();
    void set_stand(long s);
    
    // Getter und Setter
    std::string get_name();
    void set_name(std::string n);

    // Funktion zum Drucken der Kontoinformationen
    void print();
};

#endif
