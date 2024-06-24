#ifndef Feld_H
#define Feld_H

#include <string>
using namespace std;

//Enthaelt die Koordinaten - aus diesen Elementen werden die Spielfelder aufgebaut
//Zusaetzlich wird festgehalten, was sich auf diesem Feld befindet
class Feld
    {
        private:
            char spalte;
            int reihe;
            
        public:
            Feld(char newSpalte, int newReihe);
            enum class FeldStatus { Leer, Schiff, Treffer, Wasser };
            FeldStatus feldStatus = FeldStatus::Leer;
            void setStatus(FeldStatus newStatus) { feldStatus = newStatus; };
            FeldStatus getStatus() {return feldStatus; };
            
            char getSpalte(){return toupper(spalte); };
            int getReihe(){return reihe; };

            //Hier haette man auch den == Operator ueberladen koennen, aber auf diese Weise bleibt diese Option noch fuer den Fall frei,
            //dass sowohl Koordinaten als auch Feldzustand mit diesem Operator verglichen werden sollen
            bool hatGleicheKoordinaten(Feld anderesFeld)
                {
                    bool koordinatenGleich = false;
                    koordinatenGleich = ((reihe == anderesFeld.getReihe()) && (spalte == anderesFeld.getSpalte()));
                    return koordinatenGleich;
                }
    };
#endif