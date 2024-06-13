#include <iostream>
#include <vector>

int main() {
    std::vector<int> vecZahlen; // Vektor zum Speichern der eingelesenen Zahlen
    int iZahl;

    std::cout << "Geben Sie eine Liste von Ganzzahlen ein (beenden Sie die Eingabe mit einer nicht numerischen Eingabe): " << std::endl;

    // Zahlen einlesen und in den Vektor speichern
    while (std::cin >> iZahl) {
        vecZahlen.push_back(iZahl);
    }

    // Sortieren der Zahlen in aufsteigender Reihenfolge (Bubble Sort)
    for (size_t i = 0; i < vecZahlen.size(); ++i) {
        for (size_t j = i + 1; j < vecZahlen.size(); ++j) {
            if (vecZahlen[i] > vecZahlen[j]) {
                int temp = vecZahlen[i];
                vecZahlen[i] = vecZahlen[j];
                vecZahlen[j] = temp;
            }
        }
    }

    // Entfernen von doppelten Elementen
    if (!vecZahlen.empty()) {
        size_t j = 0;
        for (size_t i = 1; i < vecZahlen.size(); ++i) {
            if (vecZahlen[i] != vecZahlen[j]) {
                ++j;
                vecZahlen[j] = vecZahlen[i];
            }
        }
        vecZahlen.resize(j + 1);
    }

    // Ausgabe der sortierten und gefilterten Liste
    for (auto elem : vecZahlen) {
        std::cout << elem << std::endl;
    }

    for (const auto& i : vecZahlen) {
        std::cout << i << " ";
    }
    std::cout << std::endl;


    return 0;
}
