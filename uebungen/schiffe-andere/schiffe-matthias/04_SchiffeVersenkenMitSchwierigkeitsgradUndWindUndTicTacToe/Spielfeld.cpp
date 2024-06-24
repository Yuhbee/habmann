#include "Spielfeld.h"

//Da die Spielfelder immer quadratisch sind, muss nur die Laenge angegeben werden
void Spielfeld::initSpielfeld(int laenge)
    {
        spielfeldGroesse = laenge;
        //fuer den Neustart der Partie ist es notwendig den Vector zu leeren bevor er neu gefuellt werden kann
        felder.clear();
        //Erzeugt durch eine geschachtelte Schleife ein quadratisches Spielfeld
        //und belegt die Felder mit den passenden Koordinaten vor
        for(int i = 0; i < spielfeldGroesse; i++)
            {        
                for(int j = 0; j < spielfeldGroesse; j++)
                    {
                        //Hier wird die Hilfsklasse verwendet um aus der Zaehlvariable der inneren Schleife einen Char zu machen
                        felder.push_back(Feld{ Hilfsklasse::getCharOfInt(i), j});
                    }
            }
    }

//Geht saemtliche Felder des Spielfelds durch um den Status des Felds an den Koordinaten zu ermitteln
Feld::FeldStatus Spielfeld::getFeldStatus(Feld koordinaten)
    {
        int sfGroesse = getSpielfeldGroesse();
        Feld::FeldStatus tempStatus = Feld::FeldStatus::Leer;

        for (int i = 0; i < (sfGroesse * sfGroesse); i++)
            {
                Feld tempFeld = getFeld(i);
                if (tempFeld.hatGleicheKoordinaten(koordinaten))
                    {
                        tempStatus = tempFeld.getStatus();
                        //Wurde das Feld gefunden, muss nicht mehr weiter gesucht werden
                        break;
                    }
            }

        return tempStatus;
    }

//Geht saemtliche Felder des Spielfelds durch um das Feld an den Koordinaten zurueckzuliefern
Feld& Spielfeld::getFeldReference(Feld koordinaten)
    {
        int sfGroesse = getSpielfeldGroesse();

        for (int i = 0; i < (sfGroesse * sfGroesse); i++)
            {
                Feld& tempFeld = getFeldReference(i);
                if (tempFeld.hatGleicheKoordinaten(koordinaten))
                    {
                        //Wurde das Feld gefunden, muss nicht mehr weiter gesucht werden
                        //Hier wird direkt der Fund zurueckgeliefert, ohne ueber eine Zwischenvariable zu gehen
                        return tempFeld;
                    }
            }

        //Diese Definition entspricht dem Leerfeld, wie es in Feld.cpp festgelegt wurde
        //um Anzuzeigen, dass das gesuchte Feld nicht auf dem Spielfeld vorhanden ist
        Feld tempFeld{ 'X', 99 };
        return tempFeld;
    }

//Geht saemtliche Felder des Spielfelds durch und zaehlt wie oft der gefragte Status vorkommt
int Spielfeld::getFeldStatusCount(Feld::FeldStatus checkStatus)
    {
        int feldstatusCount = 0;
        int sfGroesse = getSpielfeldGroesse();

        for (int i = 0; i < (sfGroesse * sfGroesse); i++)
            {
                Feld tempFeld = getFeld(i);
                if (tempFeld.getStatus() == checkStatus)
                    {
                        feldstatusCount++;
                    }
            }

        return feldstatusCount;
    }

//Aehnlich der Zaehlfunktion, nur werden hier die Felder mit dem betreffenden Status zurueckgesetzt
void Spielfeld::entferneFeldstatus(Feld::FeldStatus checkStatus)
    {
        int sfGroesse = getSpielfeldGroesse();
        Feld::FeldStatus tempStatus = Feld::FeldStatus::Leer;

        for (int i = 0; i < (sfGroesse * sfGroesse); i++)
            {
                Feld& tempFeld = getFeldReference(i);
                if (tempFeld.getStatus() == checkStatus)
                    {
                        tempFeld.setStatus(Feld::FeldStatus::Leer);
                    }
            }
    }
