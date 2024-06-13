#include <iostream>

// Funktion zum Sortieren von drei Variablen in aufsteigender Reihenfolge
void sortieren(int& a, int& b, int& c)
{
    if (a > b) std::swap(a, b);
    if (a > c) std::swap(a, c);
    if (b > c) std::swap(b, c);
}

int main()
{
    int a = 3;
    int b = 2;
    int c = 1;

    std::cout << "\n\n  Vor dem Sortieren: " << a << " " << b << " " << c << "\n\n\n";

    // Aufruf der Sortierfunktion
    sortieren(a, b, c);

    std::cout << "\n  Nach dem Sortieren: " << a << " " << b << " " << c << "\n\n\n";

    return 0;
}
