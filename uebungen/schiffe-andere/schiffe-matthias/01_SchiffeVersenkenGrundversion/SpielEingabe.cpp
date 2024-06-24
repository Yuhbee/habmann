#include "SpielEingabe.h"

Feld SpielEingabe::eingabeFeldKoordinaten()
    {
        int reihe = 0;
        char spalte = 0;
        
        //Ein Feld beim Schiffe versenken besteht aus einem Buchstaben und einer Zahl
        //diese werden hier eingelesen
        std::cin >> spalte;
        std::cin >> reihe;
        
        //und zu einem Objekt der Feldklasse zusammengesetzt. Ob dieses valide ist
        //ist hier nicht bekannt und auch nicht von Bedeutung, die Eingabe enthaelt keinerlei Logik
        Feld tempFeld{spalte, reihe};
        return tempFeld;
    }

bool SpielEingabe::pressAnyKey()
    {
        char anyKey;
        cin >> anyKey;
        return true;
    }

bool SpielEingabe::nochmalEingabe()
    {
        bool wiederholungGewuenscht = false;
        char wiederholung = ' ';
        std::cin >> wiederholung;
        if ((wiederholung == 'j') || (wiederholung == 'J'))
            {
                wiederholungGewuenscht = true;
            }

        return wiederholungGewuenscht;
    }
