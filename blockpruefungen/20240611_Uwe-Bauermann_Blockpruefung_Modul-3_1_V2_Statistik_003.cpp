#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>

// Globale Variablen zur Speicherung der Eingabedaten und Ergebnisse
// ... weil es einfach praktisch ist! ;-)
std::vector<int> g_vecZahlen = {5, 2, 9, 1, 5, 6};
std::map<std::string, double> g_mapErgebnisse;

// Funktion zur Berechnung des Medians
void vBerechneMedian() {
    std::vector<int> vecSortierteZahlen = g_vecZahlen; // Kopie für Sortierung
    std::sort(vecSortierteZahlen.begin(), vecSortierteZahlen.end());
    size_t nGroesse = vecSortierteZahlen.size();
    double dMedian;
    if (nGroesse % 2 == 0) {
        dMedian = (vecSortierteZahlen[nGroesse / 2 - 1] + vecSortierteZahlen[nGroesse / 2]) / 2.0;
    } else {
        dMedian = vecSortierteZahlen[nGroesse / 2];
    }
    g_mapErgebnisse["Median"] = dMedian;
}

// Funktion zur Berechnung des Durchschnitts
void vBerechneDurchschnitt() {
    double dSumme = std::accumulate(g_vecZahlen.begin(), g_vecZahlen.end(), 0.0);
    double dDurchschnitt = dSumme / g_vecZahlen.size();
    g_mapErgebnisse["Durchschnitt"] = dDurchschnitt;
}

// Funktion zur Bestimmung des Modus
void vBerechneModus() {
    std::map<int, int> mapHaeufigkeit;
    for (int iWert : g_vecZahlen) {
        mapHaeufigkeit[iWert]++;
    }
    
    int iModus = g_vecZahlen[0];
    int iMaxHaeufigkeit = 0;
    for (const auto& paar : mapHaeufigkeit) {
        if (paar.second > iMaxHaeufigkeit) {
            iMaxHaeufigkeit = paar.second;
            iModus = paar.first;
        }
    }
    
    g_mapErgebnisse["Modus"] = iModus;
}

// Funktion zur Berechnung der Standardabweichung
void vBerechneStandardabweichung() {
    double dDurchschnitt = g_mapErgebnisse["Durchschnitt"];
    double dSumme = 0.0;
    for (int iWert : g_vecZahlen) {
        dSumme += (iWert - dDurchschnitt) * (iWert - dDurchschnitt);
    }
    double dStandardabweichung = std::sqrt(dSumme / g_vecZahlen.size());
    g_mapErgebnisse["Standardabweichung"] = dStandardabweichung;
}

// Funktion zur Ausgabe der Ergebnisse
void vAusgabeErgebnisse() {
    // Bildschirm loeschen (systemabhaengig)
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    // Rahmen und detaillierte Ausgabe
    std::cout << "=========================================\n";
    std::cout << "           Statistische Analyse          \n";
    std::cout << "=========================================\n\n";

    std::cout << "Eingegebene Zahlen (sortiert):\n";
    std::cout << "------------------------------\n";
    std::vector<int> vecSortierteZahlen = g_vecZahlen;
    std::sort(vecSortierteZahlen.begin(), vecSortierteZahlen.end());
    for (int iWert : vecSortierteZahlen) {
        std::cout << "  " << iWert << "\n";
    }
    std::cout << "\n";

    std::cout << "Ergebnisse:\n";
    std::cout << "-----------\n";
    std::cout << "Median              : " << g_mapErgebnisse["Median"] << "\n";
    std::cout << "Durchschnitt        : " << g_mapErgebnisse["Durchschnitt"] << "\n";
    std::cout << "Modus               : " << g_mapErgebnisse["Modus"] << "\n";
    std::cout << "Standardabweichung  : " << g_mapErgebnisse["Standardabweichung"] << "\n";
    std::cout << "\n=========================================\n";
}

int main() {
    vBerechneMedian();
    vBerechneDurchschnitt();
    vBerechneModus();
    vBerechneStandardabweichung();

    vAusgabeErgebnisse();

    return 0;
}
