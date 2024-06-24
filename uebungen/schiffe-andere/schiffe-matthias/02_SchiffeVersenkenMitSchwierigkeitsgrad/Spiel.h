#ifndef Spiel_H
#define Spiel_H

#include "SpielDarstellung.h"
#include "SpielEingabe.h"
#include "SpielLogik.h"

#include "Spielfeld.h"

#include "Spieler.h"


//Die zentrale Klasse, hierin findet das eigentliche Spiel statt, 
//da hier saemtliche Spielrelevanten Daten (durch die Spieler und deren Attribute) festgehalten werden das M des Model View Controller
using namespace std;
class Spiel
    {
        public:
            //Der Einsatz des Enums erleichtert die lesbarkeit der State Machine und das nachvollziehen von Uebergaengen und Ablaeufen
            enum class SpielState { StartState, SpielerPlatziertSchiffe, ComputerPlatziertSchiffe, SpielerMachtZug, ComputerMachtZug, SpielEnde};
            Spiel();

        private:
            //eine(nicht ganz konsequent umgesetzte) Umsetzung des Model View Controllers
            //https://de.wikipedia.org/wiki/Model_View_Controller
            //Indem Logik, Darstellung und Eingabe in jeweils seperate Klassen zerlegt wurden
            SpielDarstellung spielDarstellung;
            SpielEingabe spielEingabe;
            SpielLogik spielLogik;

            //State Machine Code, hier koennte prinzipiell auf das Check Transition verzichtet werden
            //wenn die Uebergaenge zwischen den States ebenfalls in enterState abgehandelt werden
            SpielState currentState = SpielState::StartState;
            void enterState(SpielState newState);
            void checkTransition();

            //Keine wirkliche Anzeigefunktion, hier werden mehrfach benoetigte Aufrufe der spielDarstellung zusammengefasst
            void spielfeldanzeigeAktualisieren();

            Spieler menschSpieler;
            Spieler computerSpieler;
    };
#endif