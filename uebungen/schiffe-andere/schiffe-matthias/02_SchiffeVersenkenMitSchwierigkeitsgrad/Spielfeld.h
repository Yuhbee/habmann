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

            Feld::FeldStatus getFeldStatus(Feld koordinaten);
            int getFeldStatusCount(Feld::FeldStatus checkStatus);
    };
#endif