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
        
        if (menschSpieler.spielendePruefen())
            {
                if (computerSpieler.spielendePruefen())
                    {
                        sieger = 0;
                    }
                else
                    {
                        sieger = 1;
                    }
            }
        else
            {
                if (computerSpieler.spielendePruefen())
                    {
                        sieger = 2;
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
                                computerSpieler.insertSchiff(Schiff{ tempFeld });
                                schiffZahl--;
                            }
                    };
                feldGueltig = false;
            };
    }

void SpielLogik::zufaelligeSchusspositionierung(Spieler& computerSpieler, Spieler& menschSpieler)
    {
        bool feldGueltig = false;
        int maxZahl = computerSpieler.getSpielfeld().getSpielfeldGroesse();


        while (!feldGueltig)
            {
                Feld tempFeld{ Hilfsklasse::getCharOfInt(std::rand() % maxZahl), std::rand() % maxZahl };
                feldGueltig = pruefungEingabe(tempFeld, computerSpieler.getZielfeld(), Feld::FeldStatus::Leer);
                if (feldGueltig)
                    {
                        switch (menschSpieler.getSpielfeld().getFeldStatus(tempFeld))
                            {
                                case Feld::FeldStatus::Leer:
                                    aendereFeldstatus(tempFeld, computerSpieler.getZielfeld(), Feld::FeldStatus::Wasser);
                                    aendereFeldstatus(tempFeld, menschSpieler.getSpielfeld(), Feld::FeldStatus::Wasser);
                                    break;
                                case Feld::FeldStatus::Schiff:
                                    aendereFeldstatus(tempFeld, computerSpieler.getZielfeld(), Feld::FeldStatus::Treffer);
                                    aendereFeldstatus(tempFeld, menschSpieler.getSpielfeld(), Feld::FeldStatus::Treffer);
                                    break;
                                default:
                                    break;
                            }
                    }
            };
    }
