#include "Schiff.h"
#include "Hilfsklasse.h"

void Schiff::windBerechnung(Hilfsklasse::Windrichtung windrichtung, int spielfeldGroesse)
    {
        char tempSpalte = ankerplatz.getSpalte();
        //um zu rechnen wird die Spalte ebenfalls temporaer in einen intwert umgewandelt
        int tempSpaltenInt = Hilfsklasse::getIntOfChar(tempSpalte);
        int tempReihe = ankerplatz.getReihe();

        switch (windrichtung)
            {
                case Hilfsklasse::Windrichtung::Windstill:
                    //Hier wuerde das Programm ueberhaupt nicht in die Windberechnung springen,
                    //nur der vollstaendigkeit halber angegeben
                    break;
                case Hilfsklasse::Windrichtung::Nord:
                    tempSpaltenInt++;
                    if (tempSpaltenInt >= spielfeldGroesse)
                        {
                            //Die Erde ist eine Kugel, also kommen Schiffe die ueber den Rand segeln wieder an der anderen Seite heraus
                            tempSpaltenInt = 0;
                        }

                    //Um die neue Position zu setzen muss der Wert wieder zurueckkonvertiert werden
                    tempSpalte = Hilfsklasse::getCharOfInt(tempSpaltenInt);
                    ankerplatz.setSpalte(tempSpalte);
                    break;
                case Hilfsklasse::Windrichtung::Ost:
                    tempReihe--;
                    if (tempReihe < 0)
                        {
                            //Die Erde ist eine Kugel, also kommen Schiffe die ueber den Rand segeln wieder an der anderen Seite heraus
                            tempReihe = (spielfeldGroesse - 1);
                        }

                    ankerplatz.setReihe(tempReihe);
                    break;
                case Hilfsklasse::Windrichtung::Sued:
                    tempSpaltenInt--;
                    if (tempSpaltenInt < 0)
                        {
                            //Die Erde ist eine Kugel, also kommen Schiffe die ueber den Rand segeln wieder an der anderen Seite heraus
                            tempSpaltenInt = (spielfeldGroesse - 1);
                        }

                    //Um die neue Position zu setzen muss der Wert wieder zurueckkonvertiert werden
                    tempSpalte = Hilfsklasse::getCharOfInt(tempSpaltenInt);
                    ankerplatz.setSpalte(tempSpalte);
                    break;
                case Hilfsklasse::Windrichtung::West:
                    tempReihe++;
                    if (tempReihe >= spielfeldGroesse)
                        {
                            //Die Erde ist eine Kugel, also kommen Schiffe die ueber den Rand segeln wieder an der anderen Seite heraus
                            tempReihe = 0;
                        }

                    ankerplatz.setReihe(tempReihe);
                    break;
                default:
                    break;
            }
        int i = 0;
    }

bool Schiff::pruefeTreffer(Feld zielFeld)
    {
        bool trefferRegistriert = false;
        if (zielFeld.hatGleicheKoordinaten(ankerplatz))
            {
                trefferPunkte--;
                trefferRegistriert = true;
            }

        return trefferRegistriert;
    }

//Das Schiff kuemmert sich selbst um die erstellung des Infostrings, somit muessen nicht allzuviele Variablen
//nach aussen durchgereicht werden und die Informationen koennen beliebig erweitert werden
string Schiff::getSchiffInfoString()
    {
        string infoString = "";
        infoString += "HP: " + to_string(trefferPunkte);
        return infoString;
    }
