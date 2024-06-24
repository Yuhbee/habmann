#include "SpielLogik.h"

bool SpielLogik::pruefungEingabe(Feld checkFeld, Spielfeld checkSpielfeld, Feld::FeldStatus checkStatus)
    {
        int sfGroesse = checkSpielfeld.getSpielfeldGroesse();
        bool validierung = false;
        
        for(int i = 0; i < (sfGroesse * sfGroesse); i++)
            {  
                Feld tempFeld = checkSpielfeld.getFeld(i);
                if(tempFeld.hatGleicheKoordinaten(checkFeld))
                    {
                        if (tempFeld.getStatus() == checkStatus)
                            {
                                validierung = true;
                                break;
                            }
                    }
            }
        
        return validierung;
    }

int SpielLogik::spielendePruefen(Spieler& menschSpieler, Spieler& computerSpieler)
    {
        int sieger = -1;
        
        //Durch die Umkehrung der Logik zur Vorversion liefert spielendePruefen nun true zurueck, wenn der fragliche Spieler
        //verloren hat, nicht mehr wenn er gewonnen hat, deswegen muessen die Rueckgabewerte dieser Funktion ebenfalls angepasst werden
        if (menschSpieler.spielendePruefen())
            {
                if (computerSpieler.spielendePruefen())
                    {
                        //das Unentschieden bleibt gleich - wenn beide Verloren haben, ist es ein Unentschieden
                        sieger = 0;
                    }
                else
                    {
                        //Hier wurde aus der 1 eine 2 um der invertierten Logik in Spieler.spielendePruefen() Rechnung zu tragen
                        sieger = 2;
                    }
            }
        else
            {
                if (computerSpieler.spielendePruefen())
                    {
                        //Hier wurde aus der 2 eine 1 um der invertierten Logik in Spieler.spielendePruefen() Rechnung zu tragen
                        sieger = 1;
                    }
            }

        return sieger;
    }
    
void SpielLogik::aendereFeldstatus(Feld changeFeld, Spielfeld& checkSpielfeld, Feld::FeldStatus newStatus)
    {
        int sfGroesse = checkSpielfeld.getSpielfeldGroesse();
        bool validierung = false;
        
        for(int i = 0; i < (sfGroesse * sfGroesse); i++)
            {  
                Feld& tempFeld = checkSpielfeld.getFeldReference(i);
                if(tempFeld.hatGleicheKoordinaten(changeFeld))
                    {
                        tempFeld.setStatus(newStatus);                    
                        break;
                    }
            }
    }

void SpielLogik::zufaelligeSchiffspositionierung(Spieler& computerSpieler)
    {
        bool feldGueltig = false;
        int schiffZahl = computerSpieler.getSchiffanzahl();

        int maxZahl = computerSpieler.getSpielfeld().getSpielfeldGroesse();

        while (schiffZahl > 0)
            {
                while (!feldGueltig)
                    {
                        Feld tempFeld{ Hilfsklasse::getCharOfInt(std::rand() % maxZahl), std::rand() % maxZahl};
                        feldGueltig = pruefungEingabe(tempFeld, computerSpieler.getSpielfeld(), Feld::FeldStatus::Leer);
                        if (feldGueltig)
                            {
                                aendereFeldstatus(tempFeld, computerSpieler.getSpielfeld(), Feld::FeldStatus::Schiff);
                                //Auch an dieser Stelle muessen den Schiffen die Trefferpunkte mitgegeben werden
                                computerSpieler.insertSchiff(Schiff{ tempFeld, computerSpieler.getSchiffTrefferpunkte()});
                                schiffZahl--;
                            }
                    };
                feldGueltig = false;
            };
    }

void SpielLogik::zufaelligeSchusspositionierung(Spieler& computerSpieler, Spieler& menschSpieler, bool mitWindberechnung)
    {
        bool feldGueltig = false;
        int maxZahl = computerSpieler.getSpielfeld().getSpielfeldGroesse();

        while (!feldGueltig)
            {
                Feld tempFeld{ Hilfsklasse::getCharOfInt(std::rand() % maxZahl), std::rand() % maxZahl };
                feldGueltig = pruefungEingabe(tempFeld, computerSpieler.getZielfeld(), Feld::FeldStatus::Leer);
                if (feldGueltig)
                    {
                        if (menschSpieler.pruefeTreffer(tempFeld))
                            {
                                if (!mitWindberechnung)
                                    {
                                        //befand sich an diser Stelle ein Schiff, wird ein Treffer vermerkt
                                        aendereFeldstatus(tempFeld, computerSpieler.getZielfeld(), Feld::FeldStatus::Treffer);
                                        aendereFeldstatus(tempFeld, menschSpieler.getSpielfeld(), Feld::FeldStatus::Treffer);
                                        //Aber nur wenn kein Wind weht, fuer die Begruendung siehe Spiel.cpp
                                    }
                            }
                        else
                            {
                                if (!mitWindberechnung)
                                    {
                                        //Bei den Fehlschuessen wird aus dem genannten Grund ebenfalls nur ohne Wind der Status des Felds geaendert
                                        aendereFeldstatus(tempFeld, computerSpieler.getZielfeld(), Feld::FeldStatus::Wasser);
                                        aendereFeldstatus(tempFeld, menschSpieler.getSpielfeld(), Feld::FeldStatus::Wasser);
                                    }
                            }
                    }
            };
    }
