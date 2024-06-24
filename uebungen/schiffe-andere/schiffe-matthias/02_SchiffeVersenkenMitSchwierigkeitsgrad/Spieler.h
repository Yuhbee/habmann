#ifndef Spieler_H
#define Spieler_H

#include "Schiff.h"
#include "Spielfeld.h"

#include <string>
#include <vector>

using namespace std;

//Die Spielerklasse enthaelt saemtliche Daten, die fuer den jeweiligen Spieler wichtig sind, das Spiel kennt diese Werte nicht
//aber es kennt beide Spieler und kann ueber die public Funktionen auf die notwendigen Informationen zugreifen
class Spieler
    {
        private:
            string spielerName;
            int anzahlSchiffe = 0;

            Spielfeld spielfeld;
            Spielfeld zielfeld;


        protected:
            vector<Schiff> flotte;

        public:
            string getName() { return spielerName; }

            Spielfeld& getSpielfeld() { return spielfeld; };
            Spielfeld& getZielfeld() { return zielfeld; };

            int getSchiffanzahl() { return anzahlSchiffe; }

            int getFlottengroesse() { return flotte.size(); }
            Schiff& getSchiffAt(int schiffNummer) { return flotte.at(schiffNummer); };
            void insertSchiff(Schiff neuesSchiff);

            void initSpieler(int feldBreite, int zielFeldBreite);

            bool spielendePruefen();
    };
#endif
