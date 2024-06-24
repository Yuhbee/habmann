#ifndef SpielLogik_H
#define SpielLogik_H

#include "Feld.h"
#include "Spielfeld.h"
#include "Spieler.h"

//Hier werden die "Spielentscheidungen" getroffen, in dieser Ausbaustufe sind es reine Zufallsfunktionen die fuer Schiffe, die nur ein Feld belegen
//auch ausreichen. Soll das Spiel ausgebaut werden um groessere Schiffe zu unterstuetzen kann durch die Uebergabe des Computerspielers dessen vorhandene/bekannte
//Daten verwendet werden um eine informierte Entscheidung zu treffen, wohin der Schuss platziert werden soll.
//Eine weitere Moeglichkeit waere es, diese Logik in eine eigene SchiffeVersenkenKi.cpp Klasse auszulagern und diese in eine von Spieler.cpp abgeleitete Klasse
//einzubinden um so eine umfassende Computerspieler Klasse zur Verfuegung zu stellen
class SpielLogik
    {
        private:
        
        public:
            void zufaelligeSchiffspositionierung(Spieler& computerSpieler);
            void zufaelligeSchusspositionierung(Spieler& computerSpieler, Spieler& menschSpieler);
            bool pruefungEingabe(Feld checkFeld, Spielfeld checkSpielfeld, Feld::FeldStatus checkStatus);
            int spielendePruefen(Spieler& menschSpieler, Spieler& computerSpieler);

            void aendereFeldstatus(Feld changeFeld, Spielfeld& checkSpielfeld, Feld::FeldStatus newStatus);
    };
#endif
