#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Funktion zum Schreiben der Studenteninformationen in die Datei
void schreibeStudentenInDatei(const string& dateiName, int nAnzahl) {
    ofstream datei(dateiName, ios::app); // Oeffne die Datei im Anhaengemodus
    
    if (!datei.is_open()) {
        cout << "Fehler beim Oeffnen der Datei." << endl;
        return;
    }

    for (int i = 0; i < nAnzahl; ++i) {
        string sVorname, sNachname, sStudiengang;
        int nAlter;

        cout << "Geben Sie die Informationen fuer Student " << i + 1 << " ein:" << endl;
        cout << "Vorname: ";
        cin >> sVorname;
        cout << "Nachname: ";
        cin >> sNachname;
        cout << "Alter: ";
        cin >> nAlter;
        cout << "Studiengang: ";
        cin >> sStudiengang;

        datei << sVorname << " " << sNachname << " " << nAlter << " " << sStudiengang << endl;
    }

    datei.close();
}

// Funktion zum Lesen der Studenteninformationen aus der Datei und Ausgabe auf der Konsole
void leseStudentenAusDatei(const string& dateiName) {
    ifstream datei(dateiName);
    
    if (!datei.is_open()) {
        cout << "Fehler beim Oeffnen der Datei." << endl;
        return;
    }

    string zeile;
    while (getline(datei, zeile)) {
        cout << zeile << endl;
    }

    datei.close();
}

int main() {
    string sDateiName = "studenten.txt";
    int nAnzahl;

    cout << "Geben Sie die Anzahl der Studenten ein: ";
    cin >> nAnzahl;

    schreibeStudentenInDatei(sDateiName, nAnzahl);
    leseStudentenAusDatei(sDateiName);

    return 0;
}
