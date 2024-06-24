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

int SpielLogik::spielendePruefenTTT(Spieler& menschSpieler, Spieler& computerSpieler)
    {
        int sieger = -1;
        Spielfeld tempSpielfeld = menschSpieler.getSpielfeld();
        int sfGroesse = tempSpielfeld.getSpielfeldGroesse();

        //Da die Felder im Spielfeld nicht in Reihen und Spalten organisiert werden, 
        //muessen diese Informationen hier aus den vorhandenen Werten gewonnen werden
        int rowXCount[3] = { 0, 0, 0 };
        int rowOCount[3] = { 0, 0, 0 };

        int columnXCount[3] = { 0, 0, 0 };
        int columnOCount[3] = { 0, 0, 0 };

        int diagonalXCount[2] = { 0, 0 };
        int diagonalOCount[2] = { 0, 0 };

        //Hier verhaelt es sich identisch zur Spieldarstellung
        int rowCounter = 0;
        int columnCounter = 0;

        //wird zweimal benoetigt, daher macht es Sinn, eine lokale Variable anzufuellen 
        // um nicht zweimal die selbe Berechnung durchfuehren zu muessen
        int anzahlLeerfelder = tempSpielfeld.getFeldStatusCount(Feld::FeldStatus::Leer);

        if (anzahlLeerfelder < 5)
            {
                //Die Pruefung macht erst Sinn, sobald 5 Symbole platziert worden sind
                for (int i = 0; i < (sfGroesse * sfGroesse); i++)
                    {
                        Feld& tempFeld = tempSpielfeld.getFeldReference(i);
                        switch (tempFeld.getStatus())
                            {
                                case Feld::FeldStatus::Treffer:
                                    rowXCount[rowCounter]++;
                                    columnXCount[columnCounter]++;

                                    if (rowCounter == columnCounter)
                                        {
                                            diagonalXCount[0]++;
                                        }

                                    //Die zweite Diagonale beinhaltet die Felder 0|2, 1|1 und 2|0 - 
                                    //somit laesst sich leicht berechnen, ob eines dieser Felder gefunden wurde
                                    if ((rowCounter + columnCounter) == 2)
                                        {
                                            diagonalXCount[1]++;
                                        }
                                    break;
                                case Feld::FeldStatus::Wasser:
                                    rowOCount[rowCounter]++;
                                    columnOCount[columnCounter]++;

                                    if (rowCounter == columnCounter)
                                        {
                                            diagonalOCount[0]++;
                                        }

                                    //Die zweite Diagonale beinhaltet die Felder 0|2, 1|1 und 2|0 - 
                                    //somit laesst sich leicht berechnen, ob eines dieser Felder gefunden wurde
                                    if ((rowCounter + columnCounter) == 2)
                                        {
                                            diagonalOCount[1]++;
                                        }
                                    break;
                                default:
                                    break;
                            }
                        //Nachdem die Breite des Felds erreicht wurde, muss in die naechste Zeile
                        //umgebrochen werden, dafuer werden die Zeilen mitgezaehlt
                        rowCounter++;

                        if (rowCounter == (sfGroesse))
                            {
                                //In der naechsten Zeile faengt alles wieder in der ersten Spalte an
                                rowCounter = 0;
                                columnCounter++;
                            }
                    }
            }

        //Nun da die Felder strukturiert gezaehlt wurden, kann die Auswertung durchgefuehrt werden
        for (int i = 0; i < 3; i++)
            {
                if ((rowXCount[i] == 3) || (columnXCount[i] == 3))
                    {
                        sieger = 1;
                    }
                else if ((rowOCount[i] == 3) || (columnOCount[i] == 3))
                    {
                        sieger = 2;
                    }
            }

        //Bei den Diagonalen genuegt  eine Abfrage, eine Schleife ist hier nicht zwingend notwendig
        if ((diagonalXCount[0] == 3) || (diagonalXCount[1] == 3))
            {
                sieger = 1;
            }
        else if ((diagonalOCount[0] == 3) || (diagonalOCount[1] == 3))
            {
                sieger = 2;
            }

        if ((sieger == -1) && (anzahlLeerfelder == 0))
            {
                //Wurden alle Felder belegt aber kein Sieger ermittelt, endet das Spiel unentschieden
                sieger = 0;
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

void SpielLogik::zufaelligeTTTpositionierung(Spieler& computerSpieler, Spieler& menschSpieler)
    {
        bool feldGueltig = false;
        int maxZahl = computerSpieler.getSpielfeld().getSpielfeldGroesse();

        while (!feldGueltig)
            {
                Feld tempFeld{ Hilfsklasse::getCharOfInt(std::rand() % maxZahl), std::rand() % maxZahl };
                //Hier wird auf das Spielfeld, nicht das Zielfeld abgefragt, da dieses beim Tic Tac Toe nicht aktualisiert wird
                feldGueltig = pruefungEingabe(tempFeld, computerSpieler.getSpielfeld(), Feld::FeldStatus::Leer);
                if (feldGueltig)
                    {
                        //In dieser einfachen Variante hat der Computer immer O - das koennte man weiter ausbauen, dann muesste entweder
                        //uebergeben werden, welches Symbol gesetzt werden soll, oder dieser Wert koennte in der Spielerklasse festgehalten werden
                        aendereFeldstatus(tempFeld, computerSpieler.getSpielfeld(), Feld::FeldStatus::Wasser);
                        aendereFeldstatus(tempFeld, menschSpieler.getSpielfeld(), Feld::FeldStatus::Wasser);
                    }
            };
    }

