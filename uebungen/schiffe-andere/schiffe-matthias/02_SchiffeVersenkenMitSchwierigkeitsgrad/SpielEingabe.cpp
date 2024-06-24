#include "SpielEingabe.h"
#include <algorithm> // fuer std:find() (ub)

Feld SpielEingabe::eingabeFeldKoordinaten()
    {
        int reihe = 0;
        char spalte = 0;
        
        //Ein Feld beim Schiffe versenken besteht aus einem Buchstaben und einer Zahl
        //diese werden hier eingelesen
        cin >> spalte;
        cin >> reihe;
        
        //und zu einem Objekt der Feldklasse zusammengesetzt. Ob dieses valide ist
        //ist hier nicht bekannt und auch nicht von Bedeutung, die Eingabe enthaelt keinerlei Logik
        Feld tempFeld{spalte, reihe};
        return tempFeld;
    }

bool SpielEingabe::nochmalEingabe()
    {
        bool wiederholungGewuenscht = false;
        char wiederholung = ' ';
        cin >> wiederholung;
        if ((wiederholung == 'j') || (wiederholung == 'J'))
            {
                wiederholungGewuenscht = true;
            }

        return wiederholungGewuenscht;
    }

int SpielEingabe::eingabeInt(vector<int> gueltigeWerte)
    {
        int eingegebenerInt;
        cin >> eingegebenerInt;
        if(!(std::find(gueltigeWerte.begin(), gueltigeWerte.end(), eingegebenerInt) != gueltigeWerte.end()))
            {
                //Wenn der eingegebene Wert sich nicht unter den vorgegebenen befindet, wird der erste Wert der gueltigen Werte verwendet
                eingegebenerInt = gueltigeWerte.at(0);
            }

        return eingegebenerInt;
    }