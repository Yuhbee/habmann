#include "SpielDarstellung.h"

void SpielDarstellung::spielerBegruessen()
    {
        cout << "Ahoi du Landratte, mach dich bereit ein paar Schiffe zu versenken" << "\n";
    }

void SpielDarstellung::schwierigkeitsGradAufforderung()
    {
        cout << "Der Pessimist klagt über den Wind, der Optimist hofft, dass er dreht, der Realist richtet das Segel aus.\n Wie schwer darf es denn werden?" << "\n";
        cout << "-1- Schiffsjunge" << "\n";
        cout << "-2- Leichtmatrose" << "\n";
        cout << "-3- Erster Maat" << "\n";
        cout << "-4- Kapitaen" << "\n";
        cout << "-5- Admiral" << "\n";
    }

void SpielDarstellung::spielfeldZeichnen(Spielfeld& spielfeld)
    {        
        //Die Spielfeldgroesse ist von elementarer Wichtigkeit um die Anzeige umzusetzen, deswegen wird sie einmalig in einer lokalen Variable festgehalten
        int sfGroesse = spielfeld.getSpielfeldGroesse();

        //Hier werden die einzelnen "Puzzleteile" fuer die Darstellung angelegt
        string oben =  "+---+";
        
        string mitte = "|   |";
        string mitteSchiff = "| S |";
        string mitteTreffer = "| X |";
        string mitteWasser = "| 0 |";
        
        string unten=  "+---+";
        
        string obenString = "";
        string mitteString = "";
        string untenString = "";
        

        //Ueberschriften werden nur einmal generiert
        cout << "   ";
        for (int i = 0; i < sfGroesse; i++)
            {
                cout << "| " << i << " |";
            }
        cout << endl;


        int rowCounter = 0;
        int columnCounter = 0;

        for(int i = 0; i < (sfGroesse * sfGroesse); i++)
            {    
                if (rowCounter == 0)
                    {
                        obenString.append("   ");
                        string columString = " ";
                        columString += Hilfsklasse::getCharOfInt(columnCounter);
                        mitteString.append(columString);
                        mitteString.append(" ");
                        untenString.append("   ");
                    }

                //Die obere und untere Zeile eines Kastens ist immer identisch
                obenString.append(oben);
                //Abhaengig vom Status des Felds wird ein anderer Mittelteil gezeichnet
                switch(spielfeld.getFeld(i).getStatus())
                {
                    case Feld::FeldStatus::Leer:
                        //Theoretisch koennte auf den Leer Status
                        //Verzichtet werden, da das Verhalten auch ueber den default
                        //abgedeckt ist, aber sicherer ist es, ihn anzugeben
                        //falls sich der default aendern sollte. Ausserdem
                        //wird so das gewuenschte Verhalten fuer andere Entwickler deutlich
                        mitteString.append(mitte);
                        break;
                    case Feld::FeldStatus::Schiff:
                        mitteString.append(mitteSchiff);
                        break;
                    case Feld::FeldStatus::Treffer:
                        mitteString.append(mitteTreffer);
                        break;
                    case Feld::FeldStatus::Wasser:
                        mitteString.append(mitteWasser);
                        break;
                    default:
                        mitteString.append(mitte);
                        break;
                }

                //Die obere und untere Zeile eines Kastens ist immer identisch
                untenString.append(unten);

                //Nachdem die Breite des Felds erreicht wurde, muss in die naechste Zeile
                //umgebrochen werden, dafuer werden die Zeilen mitgezaehlt
                rowCounter++;

                if(rowCounter == (sfGroesse))
                    {
                        //sobald die Breite erreicht wurde wird ausgegeben 
                        cout<<obenString<<endl;
                        cout<<mitteString<<endl;
                        cout<<untenString<<endl;
                    
                        //und die naechste Zeile vorbereitet
                        obenString.clear();
                        mitteString.clear();
                        untenString.clear();

                        //In der naechsten Zeile faengt alles wieder in der ersten Spalte an
                        rowCounter = 0;
                        columnCounter++;
                    }
            }
    }

//Nun folgen einige Textausgaben, man haette diese zwar auch ohne Probleme im Spiel.cpp direkt aufrufen koennen, aber durch die Trennung kann man zum Beispiel
//eine komplett uebersetzte Ausgabe realisieren, indem man die SpielDarstellung.cpp austausch. Es gibt bessere Moeglichkeiten eine Textausgabe zu lokalisieren,
//aber auch fuer andere Vorgehen ist es einfacher, saemtliche Ausgaben gesammelt zu haben. Selbes gilt fuer eventuell vorhandene grafische Ausgaben
void SpielDarstellung::schiffPlatzierAufforderung()
    {
        cout<<"Jetzt muss die Flotte in See stechen, kuemmern wir uns darum!"<<endl;
    }
    
void SpielDarstellung::schiffPlatzierEingabeAufforderung(int anzahlSchiffe, int breite)
    {
        cout << "Es muessen noch " << anzahlSchiffe << " Schiffe zu Wasser gelassen werden" << endl;
        cout << "Lege den Kurs fest - zuerst die Spalte (A bis " << Hilfsklasse::getCharOfInt((breite - 1)) << ") und dann die Reihe(0 - " << (breite - 1) << ") danach mit Enter bestaetigen" << endl;
    }

void SpielDarstellung::schussAufforderrung(int breite)
    {
        cout << "Anlegen, Zielen Feuer! - zuerst die Spalte (A bis " << Hilfsklasse::getCharOfInt((breite - 1)) << ") und dann die Reihe(0 - " << (breite - 1) << ") danach mit Enter bestaetigen" << endl;
    }

void SpielDarstellung::nochmalAufforderung()
    {
        cout << "Das Meer ist riesig, da gibt es bestimmt noch mehr Schiffe, die versenkt werden wollen, noch eine Runde Smutje? J fuer Jarrr, alles andere fuer nein" << endl;
    }

void SpielDarstellung::ueberschriftEigenesFeld(Spieler& anzeigeSpieler)
    {
        cout << "Deine Flotte:" << endl;
        int tempSchiffzahl = anzeigeSpieler.getSpielfeld().getFeldStatusCount(Feld::FeldStatus::Schiff);
        cout << "Verbleibende Schiffe: " << tempSchiffzahl << endl;
    }

void SpielDarstellung::ueberschriftGegnerFeld(Spieler& anzeigeSpieler)
    {
        cout << endl << "Gegnerische Flotte:" << endl;
        //Diese Berechnung funktioniert so nur, wenn beide Spieler die selbe Anzahl an Schiffen haben, sollten sich diese Unterscheiden muss fuer die korrekte Anzeige
        //auch die urspruengliche Schiffanzahl des Gegners festgehalten und hier verwendet werden
        int tempSchiffzahl = anzeigeSpieler.getSchiffanzahl();
        int trefferAnzahl = anzeigeSpieler.getZielfeld().getFeldStatusCount(Feld::FeldStatus::Treffer);
        tempSchiffzahl -= trefferAnzahl;
        cout << "Verbleibende Schiffe: " << tempSchiffzahl << endl;
    }

void SpielDarstellung::gratulationsMeldungAnzeigen()
    {
        cout << "Sehr schoen, von der feindlichen Flotte ist nur noch Treibholz uebrig, keines ihrer haesslichen Schiffe versperrt noch den Blick Richtung Horizont." << endl;
        cout << "Glueckwunsch!" << endl;
    }

void SpielDarstellung::gameOverMeldungAnzeigen()
    {
        cout << "Die Ratten haben die sinkenden Schiffe verlassen, ich wuerde dir ja das selbe raten, aber es sind keine Schiffe mehr da, die du verlassen koenntest." << endl;
        cout << "Game Over!" << endl;
    }

//Beim Schiffe versenken gibt es das eigentlich nicht, aber wenn z.B. eine Zuganzahl eingefuehrt wird, kann der Fall eintreten
void SpielDarstellung::unentschiedenMeldungAnzeigen()
    {
        cout << "Keiner von Euch hat gewonnen, also habt ihr Beide verloren!" << endl;
        cout << "Unentschieden!" << endl;
    }

void SpielDarstellung::anzeigeBereinigen()
    {        
        //Unter Windows:
        system("cls");
        //Unter Linux (oder dem onlinegdb Online Compiler):
        //system("clear");
    }
