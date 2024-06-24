#include "Spiel.h"

//Diese Version bietet die Wahl eines Schwierigkeitsgrads

Spiel::Spiel()
    {
        enterState(SpielState::StartState);
    }

void Spiel::enterState(SpielState newState)
    {

        switch (newState)
        {
            case SpielState::StartState:
                {
                    spielDarstellung.spielerBegruessen();
                    spielDarstellung.schwierigkeitsGradAufforderung();

                    //Diese Werte wurden in der ersten Version noch fix festgehalten, hier wird jetzt variiert, indem Spieler und Computer
                    //unterschiedliche Spielfeldgroessen erhalten, hierdurch wird der Schwierigkeitsgrade umgesetzt
                    int spielfeldGroesse = 5;
                    int computerSpielfeldGroesse = 5;

                    int spielerTrefferpunkte = 1;
                    int computerTrefferpunkte = 1;

                    //in eingabeInt wird bei einer Fehleingabe des Nutzers einfach auf einen Standardwert korrigiert
                    //im spaeteren Verlauf (bei der Eingabe von Feldern) wird eine erneute Eingabe erzwungen
                    vector<int> gueltigeWerte = { 1, 2, 3, 4, 5 };
                    //Da diese Eingabe nun fuer zwei Switches verwendet wird, macht es Sinn, sie in einer lokalen Variable festzuhalten
                    int schwierigkeitsGrad = spielEingabe.eingabeInt(gueltigeWerte);
                    switch (schwierigkeitsGrad)
                        {
                            case 1:
                                //Schiffsjunge
                                spielfeldGroesse = 6;
                                computerSpielfeldGroesse = 3;
                                break;
                            case 2:
                                //Leichtmatrose
                                spielfeldGroesse = 5;
                                computerSpielfeldGroesse = 4;
                                break;
                            case 3:
                                //Erster Maat
                                spielfeldGroesse = 5;
                                computerSpielfeldGroesse = 5;
                                break;
                            case 4:
                                //Kapitaen
                                spielfeldGroesse = 4;
                                computerSpielfeldGroesse = 5;
                                break;
                            case 5:
                                //Admiral
                                spielfeldGroesse = 3;
                                computerSpielfeldGroesse = 6;
                                break;
                        }

                    windAktiv = false;
                    spielDarstellung.windAbfrage();
                    if (spielEingabe.bestaetigendeJaEingabe())
                        {
                            windAktiv = true;
                        }
                    //Mehrere Trefferpunkte sind in der jetzigen Ausbaustufe nur bei Wind moeglich, ohne Wind wird das Schiff
                    //bereits beim ersten Treffer versenkt. Deswegen kommen mehrfache Treffer nur bei Wind 
                    if (windAktiv)
                        {
                            //und beim leichtesten und schwersten Schwierigkeitsgrad zum tragen
                            switch (schwierigkeitsGrad)
                                {
                                    case 1:
                                        //Schiffsjunge
                                        spielerTrefferpunkte = 2;
                                        break;
                                    case 5:
                                        //Admiral
                                        computerTrefferpunkte = 2;
                                        break;
                                }
                        }

                    //Die Objekte sind bereits angelegt, hier werden sie initialisiert, nicht im Konstruktor
                    //somit kann eine weitere Runde, auch mit anderen Spielfeldgroessen leicht umgesetzt werden
                    menschSpieler.initSpieler(spielfeldGroesse, computerSpielfeldGroesse, spielerTrefferpunkte);
                    computerSpieler.initSpieler(computerSpielfeldGroesse, spielfeldGroesse, computerTrefferpunkte);

                    //Die Darstellung des Spielers ist hier noch leer, aber fuer die erste Runde Schiffsplatzierungen
                    //ist eine Visualisierung notwendig, die sonst erst nach der Eingabe im naechsten State erfolgen wuerde
                    spielDarstellung.spielfeldZeichnen(menschSpieler.getSpielfeld());
                }
                break;

            case SpielState::SpielerPlatziertSchiffe:
                {
                    spielDarstellung.schiffPlatzierAufforderung();

                    bool feldGueltig = false;
                    //Die Anzahl der Schiffe werden im jeweiligen Spieler festgehalten, durch den Aufruf von initSpieler werden diese auf die Spielfeldbreite gesetzt
                    //auch hier waere ein Ansatzpunkt um einen Schwierigkeitsgrad anzubinden, indem ein weiterer Parameter bei initSpieler eingefuehrt wird, der mehr oder
                    //weniger Schiffe zulaesst - in diesem Fall muesste aber auch geprueft werden, ob ausreichend Felder vorhanden sind um so viele Schiffe unterzubringen
                    int schiffZahl = menschSpieler.getSchiffanzahl();

                    while (schiffZahl > 0)
                        {
                            while (!feldGueltig)
                                {
                                    //An dieser Stelle zeigt sich der Model View Controller 
                                    //die Ausgabe erfolgt ueber spielDarstellung
                                    spielDarstellung.schiffPlatzierEingabeAufforderung(schiffZahl, menschSpieler.getSpielfeld().getSpielfeldGroesse());
                                    //die Eingabe durch spielEingabe
                                    Feld tempFeld = spielEingabe.eingabeFeldKoordinaten();
                                    //die Auswertung der Eingabe in spielLogik
                                    feldGueltig = spielLogik.pruefungEingabe(tempFeld, menschSpieler.getSpielfeld(), Feld::FeldStatus::Leer);
                                    //jede dieser Komponenten kann ausgetauscht werden, ohne die Funktionalitaet der anderen zu beeinflussen,
                                    //solange die Funktionsparameter und Rueckgabewerte unveraendert bleiben
                                    if (feldGueltig)
                                        {
                                            //hat der Spieler eine korrekte Eingabe getaetigt, wird das Schiff auf diesem Feld platziert
                                            spielLogik.aendereFeldstatus(tempFeld, menschSpieler.getSpielfeld(), Feld::FeldStatus::Schiff);
                                            //Hier wird das Schiff der Flotte zugeteilt, ab dieser Ausbaustufe hat dieser Wert einen groesseren Sinn,
                                            //da sich die Schiffe bei Wind bewegen koennen und eventuell auch mehr als einen Treffer verkraften
                                            menschSpieler.insertSchiff(Schiff{ tempFeld, menschSpieler.getSchiffTrefferpunkte() });
                                            schiffZahl--;
                                            //Nachdem das Schiff gesetzt wurde wird das aktuelle Spielfeld gezeichnet
                                            spielDarstellung.anzeigeBereinigen();
                                            spielDarstellung.spielfeldZeichnen(menschSpieler.getSpielfeld());
                                        }
                                };
                            feldGueltig = false;
                        };
                }
                break;

            case SpielState::ComputerPlatziertSchiffe:
                {
                    //Der Computer verwendet keinerlei Intelligenz fuer die Positionierung seiner Schiffe, diese werden rein zufaellig
                    //verteilt - es wird lediglich sichergestellt, dass nicht zwei Schiffe auf einem Feld landen
                    spielLogik.zufaelligeSchiffspositionierung(computerSpieler);
                }
                break;

            //Hier ist ein neuer State dazugekommen, damit diese Berechnungen nicht in einem der anderen States durchgefuehrt werden muessen
            case SpielState::DerWindWeht:
                windrichtung =  Hilfsklasse::Windrichtung(rand() % 5);

                menschSpieler.windBerechnung(windrichtung);
                computerSpieler.windBerechnung(windrichtung);
                break;

            case SpielState::SpielerMachtZug:
                {
                    spielfeldanzeigeAktualisieren();

                    spielDarstellung.schussAufforderrung(menschSpieler.getZielfeld().getSpielfeldGroesse());

                    bool feldGueltig = false;
                    while (!feldGueltig)
                        {
                            //fuer die Eingabe der Koordinaten
                            Feld tempFeld = spielEingabe.eingabeFeldKoordinaten();
                            //und die Pruefung des Felder werden hier die selben Funktionen verwendet wie beim Positionieren der Schiffe
                            //Die einzigen Unterschiede liegen in der Ausgabe der Aufforderung und dem vorletzten Parametern von pruefungEingabe
                            //jetzt wird auf das Zielfeld, nicht das Spielfeld abgefragt
                            feldGueltig = spielLogik.pruefungEingabe(tempFeld, menschSpieler.getZielfeld(), Feld::FeldStatus::Leer);
                            if (feldGueltig)
                                {
                                    //Wurde ein gueltiges Feld ausgewaehlt, muss geprueft werden, was sich an diesen Koordinaten befindet
                                    //Achtung - hier wird auf das Spielfeld des Gegners geprueft, nur hier sind die Schiffe, die der Computer platziert hat vermerkt
                                    //das Zielfeld des Spielers wird erst durch die Eingaben gefuellt

                                    if (computerSpieler.pruefeTreffer(tempFeld))
                                        {
                                            if (!windAktiv)
                                                {
                                                    //befand sich an diser Stelle ein Schiff, wird ein Treffer vermerkt
                                                    spielLogik.aendereFeldstatus(tempFeld, menschSpieler.getZielfeld(), Feld::FeldStatus::Treffer);
                                                    //Im Falle eines Treffers muss auch das eigentliche Spielfeld des Computers aktualisiert werden
                                                    spielLogik.aendereFeldstatus(tempFeld, computerSpieler.getSpielfeld(), Feld::FeldStatus::Treffer);
                                                }
                                            //Aber nur, wenn der Wind nicht aktiv ist - ansonsten wuerde das Feld dauerhaft als Treffer markiert
                                            //und die Abfrage feldGueltig wuerde dieses Feld nicht mehr zulassen, obwohl durch den Wind ein Schiff
                                            //auf ein bereits erfolglos beschossenes Feld fahren koennte 
                                        }
                                    else
                                        {
                                            if (!windAktiv)
                                                {
                                                    //Ging der Schuss daneben wird das Feld als Wasser markiert
                                                    spielLogik.aendereFeldstatus(tempFeld, menschSpieler.getZielfeld(), Feld::FeldStatus::Wasser);
                                                }
                                            //aus dem selben Grund aus dem keine Treffer festgehalten werden werden auch keine Fehlschuesse
                                            //vermerkt wenn der Wind weht, da diese das Feld ebenfalls dauerhaft blockieren wuerden.
                                        }
                                }
                        };
                }
                break;
            case SpielState::ComputerMachtZug:
                {
                    //Der Computer verwendet auch hier, wie bei der Platzierung keinerlei Intelligenz, auch die Schuesse werden rein zufaellig
                    //verteilt - es wird lediglich sichergestellt, dass nicht Felder die bereits einen Treffer oder einen Fehlschuss enthalten
                    //nicht erneut getroffen werden
                    spielLogik.zufaelligeSchusspositionierung(computerSpieler, menschSpieler, windAktiv);
                }
                break;

            case SpielState::SpielEnde:
                spielDarstellung.nochmalAufforderung();
                if (spielEingabe.bestaetigendeJaEingabe())
                    {
                        //Die Darstellung der letzten Partie muss aufgeraeumt werden
                        spielDarstellung.anzeigeBereinigen();
                        //Will der Spieler eine weitere Runde spielen geht es wieder in den Startzustand zurueck und alles wird auf Anfang gesetzt
                        enterState(SpielState::StartState);
                    }
                break;
        }

        currentState = newState;
        checkTransition();
    }

void Spiel::checkTransition()
    {
        //Nachdem die Logik des aktuellen States abgehandelt wurde wird hier geprueft, wie es weitergeht
        //fuer dieses Projekt haette diese Pruefung auch problemlos in enterState abgehandelt werden koennen
        switch (currentState)
            {
                case SpielState::StartState:
                    //Hier gibt es keine Pruefung, es geht direkt weiter
                    enterState(SpielState::SpielerPlatziertSchiffe);
                    break;
                case SpielState::SpielerPlatziertSchiffe:
                        {
                            enterState(SpielState::ComputerPlatziertSchiffe);
                        }
                    break;
                case SpielState::ComputerPlatziertSchiffe:
                    //Der neue State wird sofort nach der Platzierung beider Spieler aufgerufen, aber nur wenn der Wind auch wehen soll
                    if (windAktiv)
                        {
                            enterState(SpielState::DerWindWeht);
                        }
                    else
                        {
                            enterState(SpielState::SpielerMachtZug);
                        }
                    break;
                case SpielState::DerWindWeht:
                    //Ab hier ist der Ablauf wieder wie in der Vorversion
                    enterState(SpielState::SpielerMachtZug);
                    break;
                case SpielState::SpielerMachtZug:
                        {
                            //Nachdem der Spieler geschossen hat, muss geprueft werden, ob saemtliche Schiffe des Gegners versenkt wurden
                            switch (spielLogik.spielendePruefen(menschSpieler, computerSpieler))
                                {
                                    case 0:
                                        //Ein Unentschieden kann es bei dieser Ausbaustufe nicht geben, aber es waere denkbar,
                                        //eine Maximale Schusszahl einzubauen und das Spiel nach einer festgelegten Anzahl von Zuegen enden zu lassen
                                        //in diesem Fall kann es ein Unentschieden geben
                                        spielfeldanzeigeAktualisieren();
                                        spielDarstellung.unentschiedenMeldungAnzeigen();
                                        enterState(SpielState::SpielEnde);
                                        break;
                                    case 1:
                                        //Wurde alles versenkt gewinnt der Spieler und das Spiel endet
                                        spielfeldanzeigeAktualisieren();
                                        spielDarstellung.gratulationsMeldungAnzeigen();
                                        enterState(SpielState::SpielEnde);
                                        break;
                                    case 2:
                                        //Beim Schiffe versenken kann immer nur der aktive Spieler gewinnen
                                        //dieser Case ist nur der Vollstaendigkeit halber vorhanden
                                        break;

                                    default:
                                        //Ansonsten geht das Spiel mit der naechsten Runde weiter
                                        enterState(SpielState::ComputerMachtZug);
                                        break;
                                }
                        }
                    break;

                case SpielState::ComputerMachtZug:
                        {
                            switch (spielLogik.spielendePruefen(menschSpieler, computerSpieler))
                                {
                                    case 0:
                                        //Ein Unentschieden kann es bei dieser Ausbaustufe nicht geben, aber es waere denkbar,
                                        //eine Maximale Schusszahl einzubauen und das Spiel nach einer festgelegten Anzahl von Zuegen enden zu lassen
                                        //in diesem Fall kann es ein Unentschieden geben
                                        spielfeldanzeigeAktualisieren();
                                        spielDarstellung.unentschiedenMeldungAnzeigen();
                                        enterState(SpielState::SpielEnde);
                                        break;
                                    case 1:
                                        //Beim Schiffe versenken kann immer nur der aktive Spieler gewinnen
                                        //dieser Case ist nur der Vollstaendigkeit halber vorhanden
                                        break;
                                    case 2:
                                        //Wurde alles versenkt gewinnt der Computer und das Spiel endet
                                        spielfeldanzeigeAktualisieren();
                                        spielDarstellung.gameOverMeldungAnzeigen();
                                        enterState(SpielState::SpielEnde);
                                        break;

                                    default:
                                        //Ansonsten geht das Spiel mit der naechsten Runde weiter, die jetzt mit dem Wind, nicht mit dem Spielerzug beginnt, sofern das gewuenscht ist
                                        if (windAktiv)
                                            {
                                                enterState(SpielState::DerWindWeht);
                                            }
                                        else
                                            {
                                                enterState(SpielState::SpielerMachtZug);
                                            }
                                        break;
                                }
                        }
                    break;
            }
    }

void Spiel::spielfeldanzeigeAktualisieren()
    {
        spielDarstellung.anzeigeBereinigen();

        //Hier werden sowohl das eigene Feld
        spielDarstellung.ueberschriftEigenesFeld(menschSpieler, windrichtung);
        spielDarstellung.spielfeldZeichnen(menschSpieler.getSpielfeld());
        //als auch das gegnerische Feld angezeigt. Die Position der eigenen Schiffe ist bekannt, die des Gegners nicht
        //sowohl die eigenen, als auch die gegnerischen Treffer und Fehlschuesse werden nach und nach eingetragen
        spielDarstellung.ueberschriftGegnerFeld(computerSpieler);
        //Nur zu Testzwecken kann auch das Feld des Gegners angezeigt werden
        //spielDarstellung.spielfeldZeichnen(computerSpieler.getSpielfeld());
        spielDarstellung.spielfeldZeichnen(menschSpieler.getZielfeld());
    }