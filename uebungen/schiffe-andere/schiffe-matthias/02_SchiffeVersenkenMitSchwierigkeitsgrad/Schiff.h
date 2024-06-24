#ifndef Schiff_H
#define Schiff_H

#include "Feld.h"

//In der jetzigen Ausbaustufe ist diese Klasse nicht wirklich notwendig, aber sie erlaubt es ueber die Schiffe, die im Spieler bekannt sind
//auf das jeweilige Feld des Schiffes zuzugreifen
class Schiff
    {
        private:
            Feld ankerplatz;

        public:
            Schiff(Feld neuerAnkerplatz) : ankerplatz{ neuerAnkerplatz } {}
            Feld getAnkerplatz() { return ankerplatz; }
    };
#endif