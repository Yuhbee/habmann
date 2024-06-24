#ifndef Spielfeld_H
#define Spielfeld_H

#include "Feld.h"
#include "Hilfsklasse.h"
#include <vector>
using namespace std;

class Spielfeld
    {
        private:
            vector<Feld> felder;
            int spielfeldGroesse;
            
        public:
            void initSpielfeld(int laenge);
            int getSpielfeldGroesse() { return spielfeldGroesse; };

            Feld getFeld(int feldNummer) { return felder.at(feldNummer); };
            //Soll das Feld direkt geaendert werden und nicht nur die Werte wie Koordinaten und Status
            //ausgelesen werden, muss mit der Referenz - nicht mit der Kopie gearbeitet werden
            Feld& getFeldReference(int feldNummer) {return felder.at(feldNummer); };
            //Nun wird auch eine Ueberladene Funktion benoetigt, die ein Feld zurueckliefert, dessen Koordinaten an der gesuchten Stelle liegen
            //wenn nicht direkt ueber die Feldnummer (die an der Aufrufenden Stelle evtl. nicht bekannt ist) zugegriffen werden kann
            Feld& getFeldReference(Feld koordinaten);

            Feld::FeldStatus getFeldStatus(Feld koordinaten);
            int getFeldStatusCount(Feld::FeldStatus checkStatus);

            void entferneFeldstatus(Feld::FeldStatus checkStatus);
    };
#endif