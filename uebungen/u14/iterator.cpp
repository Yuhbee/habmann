#include <iostream>
#include <vector>

int main() {
    // Erstelle einen Vektor von Integers
    std::vector<int> vecZahlen = {1, 2, 4, 4, 5};

    int idurchlauf = 1;

    // Deklariere einen Iterator für den Vektor
    std::vector<int>::iterator it;

    // Iteriere über die Elemente des Vektors mit dem Iterator
    for (it = vecZahlen.begin(); it != vecZahlen.end(); ++it) {
        std::cout << "Durchlauf Nummer:" << idurchlauf++ << " :  " << *it << " \n"; // Dereferenziere den Iterator, um auf das Element zuzugreifen
    }
    std::cout << std::endl;

    return 0;
}
