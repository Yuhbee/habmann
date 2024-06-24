#ifndef SpielEingabe_H
#define SpielEingabe_H

#include <iostream>
#include "Feld.h"

//Das V des Model View Controller, hier wird die Darstellung des Spiels durchgefuehrt, daher ist auch nur in diesen Headern iostream includiert
class SpielEingabe
    {
        private:

        public:
            Feld eingabeFeldKoordinaten();
            bool pressAnyKey();
            bool nochmalEingabe();
    };
#endif