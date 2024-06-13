#include <iostream>
#include <vector>
#include <algorithm> // für std::sort und std::unique
#include <iterator>  // für std::unique

int main() {
    std::vector<int> vecZahlen; // Vektor zum Speichern der eingelesenen Zahlen
    int iZahl;

    std::cout << "Geben Sie eine Liste von Ganzzahlen ein (beenden Sie die Eingabe mit einer nicht numerischen Eingabe): " << std::endl;

    // Zahlen einlesen und in den Vektor speichern
    while (std::cin >> iZahl) {
        vecZahlen.push_back(iZahl);
    }

    // Sortieren der Zahlen in aufsteigender Reihenfolge
    std::sort(vecZahlen.begin(), vecZahlen.end());

    // Entfernen von doppelten Elementen
    // std::unique verschiebt doppelte Elemente an das Ende des Vektors und gibt einen Iterator auf das erste doppelte Element zurück
    auto itLetzteEinzigartige = std::unique(vecZahlen.begin(), vecZahlen.end());
    // Entfernen der doppelten Elemente aus dem Vektor
    vecZahlen.erase(itLetzteEinzigartige, vecZahlen.end());

    // Ausgabe der sortierten und gefilterten Liste
    std::cout << "Sortierte und gefilterte Liste: ";
    for (const auto& i : vecZahlen) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
