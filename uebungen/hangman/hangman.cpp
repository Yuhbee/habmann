#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Eine Liste von Woertern fuer das Spiel
const vector<string> wortListe = {"computer", "programmierung", "spiel", "entwickler", "algorithmus"};

// Funktion zum Auswaehlen eines zufaelligen Wortes aus der Liste
string waehleZufaelligesWort() {
    srand(time(0));
    int nIndex = rand() % wortListe.size();
    return wortListe[nIndex];
}

// Funktion zum Anzeigen des aktuellen Fortschritts
void zeigeFortschritt(const string& wort, const vector<char>& errateneBuchstaben) {
    for (char buchstabe : wort) {
        if (find(errateneBuchstaben.begin(), errateneBuchstaben.end(), buchstabe) != errateneBuchstaben.end()) {
            cout << buchstabe << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

// Funktion zum Ueberpruefen, ob der Benutzer das Wort erraten hat
bool istWortErraten(const string& wort, const vector<char>& errateneBuchstaben) {
    for (char buchstabe : wort) {
        if (find(errateneBuchstaben.begin(), errateneBuchstaben.end(), buchstabe) == errateneBuchstaben.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    string sWort = waehleZufaelligesWort();
    vector<char> errateneBuchstaben;
    vector<char> falscheBuchstaben;
    int nMaxFehlversuche = 6;
    
    cout << "Willkommen zu Hangman!" << endl;
    cout << "Erraten Sie das Wort. Sie haben " << nMaxFehlversuche << " Versuche." << endl;

    while (true) {
        cout << "Aktueller Fortschritt: ";
        zeigeFortschritt(sWort, errateneBuchstaben);

        cout << "Bisher falsche Buchstaben: ";
        for (char buchstabe : falscheBuchstaben) {
            cout << buchstabe << " ";
        }
        cout << endl;

        char cTipp;
        cout << "Geben Sie einen Buchstaben ein: ";
        cin >> cTipp;

        if (find(errateneBuchstaben.begin(), errateneBuchstaben.end(), cTipp) != errateneBuchstaben.end() ||
            find(falscheBuchstaben.begin(), falscheBuchstaben.end(), cTipp) != falscheBuchstaben.end()) {
            cout << "Sie haben diesen Buchstaben bereits geraten. Versuchen Sie es erneut." << endl;
            continue;
        }

        if (sWort.find(cTipp) != string::npos) {
            cout << "Richtig! Der Buchstabe " << cTipp << " ist im Wort." << endl;
            errateneBuchstaben.push_back(cTipp);
        } else {
            cout << "Falsch! Der Buchstabe " << cTipp << " ist nicht im Wort." << endl;
            falscheBuchstaben.push_back(cTipp);
            --nMaxFehlversuche;
        }

        if (istWortErraten(sWort, errateneBuchstaben)) {
            cout << "Herzlichen Glueckwunsch! Sie haben das Wort erraten: " << sWort << endl;
            break;
        }

        if (nMaxFehlversuche == 0) {
            cout << "Sie haben alle Versuche aufgebraucht. Das Wort war: " << sWort << endl;
            break;
        }
    }

    return 0;
}
