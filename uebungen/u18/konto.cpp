#include "konto.h"
#include <iostream>

// Getter für den Kontostand
long Konto::get_stand() {
    return stand;
}

// Setter für den Kontostand
void Konto::set_stand(long s) {
    stand = s;
}

// Getter für den Namen
std::string Konto::get_name() {
    return name;
}

// Setter für den Namen
void Konto::set_name(std::string n) {
    name = n;
}

// Funktion zum Drucken der Kontoinformationen
void Konto::print() {
    std::cout << "Kontoinhaber: " << name << std::endl;
    std::cout << "Kontostand: " << stand << std::endl;
}
