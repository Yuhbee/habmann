#include <iostream>
#include <string>

// Überladung der print Funktion für einen int Parameter
void print(int a) {
    std::cout << "Ganzzahl: " << a << std::endl;
}

// Überladung der print Funktion für zwei int Parameter
void print(int a, int b) {
    std::cout << "Zwei Ganzzahlen: " << a << " und " << b << std::endl;
}

// Überladung der print Funktion für einen std::string Parameter
void print(const std::string& str) {
    std::cout << "Zeichenkette: " << str << std::endl;
}

int main() {
    // Aufrufen der überladenen Funktionen
    print(42);             // Ruft print(int a) auf
    print(42, 84);         // Ruft print(int a, int b) auf
    print("Hallo Welt");   // Ruft print(const std::string& str) auf

    return 0;
}
