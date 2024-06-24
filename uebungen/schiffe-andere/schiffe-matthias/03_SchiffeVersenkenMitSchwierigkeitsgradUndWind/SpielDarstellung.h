#ifndef SpielDarstellung_H
#define SpielDarstellung_H

#include "Spielfeld.h"
#include "Spieler.h"
#include "Hilfsklasse.h"

#include <iostream>

//Das V des Model View Controller, hier wird die Darstellung des Spiels durchgefuehrt, daher ist auch nur in diesen Headern iostream includiert
class SpielDarstellung
    {
        public:
            void spielerBegruessen();

            void schwierigkeitsGradAufforderung();
            void windAbfrage();

            void spielfeldZeichnen(Spielfeld& spielfeld);
            void schiffPlatzierAufforderung();
            void schiffPlatzierEingabeAufforderung(int anzahlSchiffe, int breite);
            void schussAufforderrung(int breite);
            void nochmalAufforderung();

            void ueberschriftEigenesFeld(Spieler& anzeigeSpieler, Hilfsklasse::Windrichtung windrichtung);
            void ueberschriftGegnerFeld(Spieler& anzeigeSpieler);

            void anzeigeBereinigen();

            void gratulationsMeldungAnzeigen();
            void gameOverMeldungAnzeigen();
            void unentschiedenMeldungAnzeigen();
    };
#endif