#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>

// Funktion zur Berechnung des Medians
double dFindeMedian(std::vector<int>& vecZahlen) {
    std::sort(vecZahlen.begin(), vecZahlen.end());
    size_t nGroesse = vecZahlen.size();
    if (nGroesse % 2 == 0) {
        return (vecZahlen[nGroesse / 2 - 1] + vecZahlen[nGroesse / 2]) / 2.0;
    } else {
        return vecZahlen[nGroesse / 2];
    }
}

// Funktion zur Berechnung des Durchschnitts
double dBerechneDurchschnitt(const std::vector<int>& vecZahlen) {
    double dSumme = std::accumulate(vecZahlen.begin(), vecZahlen.end(), 0.0);
    return dSumme / vecZahlen.size();
}

// Funktion zur Bestimmung des Modus
int iFindeModus(const std::vector<int>& vecZahlen) {
    std::map<int, int> mapHaeufigkeit;
    for (int iWert : vecZahlen) {
        mapHaeufigkeit[iWert]++;
    }
    
    int iModus = vecZahlen[0];
    int iMaxHaeufigkeit = 0;
    for (const auto& paar : mapHaeufigkeit) {
        if (paar.second > iMaxHaeufigkeit) {
            iMaxHaeufigkeit = paar.second;
            iModus = paar.first;
        }
    }
    
    return iModus;
}

// Funktion zur Berechnung der Standardabweichung
double dBerechneStandardabweichung(const std::vector<int>& vecZahlen) {
    double dDurchschnitt = dBerechneDurchschnitt(vecZahlen);
    double dSumme = 0.0;
    for (int iWert : vecZahlen) {
        dSumme += (iWert - dDurchschnitt) * (iWert - dDurchschnitt);
    }
    return std::sqrt(dSumme / vecZahlen.size());
}

// Funktion zur Ausgabe der Ergebnisse
void vAusgabeErgebnisse(const std::vector<int>& vecZahlen) {
    std::vector<int> vecSortierteZahlen = vecZahlen; // Kopie für Sortierung
    double dMedian = dFindeMedian(vecSortierteZahlen);
    double dDurchschnitt = dBerechneDurchschnitt(vecZahlen);
    int iModus = iFindeModus(vecZahlen);
    double dStandardabweichung = dBerechneStandardabweichung(vecZahlen);

    std::cout << "Sortierte Liste: ";
    for (int iWert : vecSortierteZahlen) {
        std::cout << iWert << " ";
    }
    std::cout << std::endl;

    std::cout << "Median: " << dMedian << std::endl;
    std::cout << "Durchschnitt: " << dDurchschnitt << std::endl;
    std::cout << "Modus: " << iModus << std::endl;
    std::cout << "Standardabweichung: " << dStandardabweichung << std::endl;
}

int main() {
    std::vector<int> vecZahlen = {5, 2, 9, 1, 5, 6};

    vAusgabeErgebnisse(vecZahlen);

    return 0;
}
