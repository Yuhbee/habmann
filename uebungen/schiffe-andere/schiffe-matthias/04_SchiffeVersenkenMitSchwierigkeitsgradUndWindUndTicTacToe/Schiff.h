#ifndef Schiff_H
#define Schiff_H

#include "Feld.h"
#include "Hilfsklasse.h"

//Durch den Wind erhaelt die Schiffsklasse nun eine groessere Bedeutung als in der vorherigen Ausbaustufe
//da die Position der Schiffe nun nicht mehr fix ist, sondern sich aendern kann. Ein Feld auf der Karte kann nur einen Zustand annehmen,
//deswegen wird im Schiff die Position geaendert und dann mit der Karte synchronisiert
//als weitere Erweiterung kommen nun die Trefferpunkte hinzu - fuer das klassische Spieleverhalten genuegt ein Treffer,
//aber nun ist es auch moeglich, das Schiff erst nach mehreren Treffern zu versenken
class Schiff
    {
        private:
            Feld ankerplatz;
            int trefferPunkte = 1;

        public:
            //Der Konstruktor muss nun erweitert werden um der Tatsache Rechnung zu tragen, dass manche Schiffe nun mehr als einen Treffer vertragen koennen
            //in der jetzigen Ausbaustufe kommt das nur auf dem hoechsten und dem niedrigsten Schwierigkeitsgrad zum tragen und auch nur dann, wenn Wind weht
            Schiff(Feld neuerAnkerplatz, int startTrefferpunkte) : ankerplatz{ neuerAnkerplatz }, trefferPunkte{ startTrefferpunkte } {}

            void windBerechnung(Hilfsklasse::Windrichtung windrichtung, int spielfeldGroesse);
            bool pruefeTreffer(Feld zielFeld);

            //ermoeglicht einen zentralen Zugriff auf den Status des Schiffs, ohne an jeder Stelle an der die Pruefung
            //notwendig ist auf die Trefferpunkte zugreifen zu muessen
            bool istSchiffGesunken() { return (trefferPunkte <= 0); }

            string getSchiffInfoString();

            Feld getAnkerplatz() { return ankerplatz; }
    };
#endif