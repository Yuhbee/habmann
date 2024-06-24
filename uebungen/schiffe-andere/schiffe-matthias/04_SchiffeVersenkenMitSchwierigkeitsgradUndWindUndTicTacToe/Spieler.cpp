#include "Spieler.h"

//In der vorliegenden Ausbaustufe hat die Flotte noch keine Bedeutung, aber hier werden die Schiffe gesammelt
void Spieler::insertSchiff(Schiff neuesSchiff)
	{
		flotte.push_back(neuesSchiff);
	}

//Nun, da die Schiffe mehrere Treffer vertragen koennen, ist eine detailierte Anzeige des Flottenzustands sinnvoll
string Spieler::getFlottenInfoString()
	{
		string flottenString = "Flottenzustand:\n";
		string aktivString = "Aktive Schiffe: ";
		string gesunkenString = "Gesunkene Schiffe: ";

		//dient nur der Darstellung fuer den Spieler
		for (auto schiff : flotte)
			{
				//Unter Wasser weht kein Wind, deswegen waere die Windberechnung fuer gesunkene Schiffe ueberfluessig
				if (!schiff.istSchiffGesunken())
					{
						aktivString += schiff.getSchiffInfoString() + " | ";
					}
				else
					{
						gesunkenString += schiff.getSchiffInfoString() + " | ";
					}
			}


		flottenString += aktivString + "\n" + gesunkenString + "\n";
		return flottenString;
	}

//Der Spieler selbst hat nur einen leeren Standardkonstruktor, aber statt eines Konstruktors der diese Werte setzt
//wird eine Funktion definiert, um auch ein mehrfaches Spielen zu ermoeglichen. 
//Sollte ein Konstruktor mit diesen Werten gewuenscht sein, kann auch einfach diese Init Funktion aufgerufen werden
void Spieler::initSpieler(int feldBreite, int zielFeldBreite, int trefferpunkteSchiff)
	{
		spielfeld.initSpielfeld(feldBreite);
		zielfeld.initSpielfeld(zielFeldBreite);
		//Die Trefefrpunkte werden im Spieler vermerkt, nicht im Spiel selbst (hier erfolgt nur die Auswertung aufgrund des Schwierigkeitsgrads)
		//oder in den Schiffen, diese haben nur den aktuellen Stand der Trefferpunkte
		schiffTrefferpunkte = trefferpunkteSchiff;

		flotte.clear();
		anzahlSchiffe = feldBreite;
	}

//Diese Funktion leitet ueber die Flotte die Windrichtung an saemtliche Schiffe des Spielers weiter
//und aktualisiert das Spielfeld entsprechend der neuen Positionen
void Spieler::windBerechnung(Hilfsklasse::Windrichtung windrichtung)
	{
		for (auto& schiff : flotte)
			{
				//Unter Wasser weht kein Wind, deswegen waere die Windberechnung fuer gesunkene Schiffe ueberfluessig
				if (!schiff.istSchiffGesunken())
					{
						schiff.windBerechnung(windrichtung, spielfeld.getSpielfeldGroesse());
					}
			}

		//Nachdem die Schiffe ihre neuen Positionen haben, muss die Karte aktualisiert werden
		spielfeldAktualisieren();
	}

//Zaehlt zusammen, wie viele Schiffe des Spielers noch seetuechtig sind
int Spieler::getSeetuechtigeSchiffsanzahl()
	{
		int seetuechtigeSchiffe = 0;

		for (auto schiff : flotte)
			{
				if (!schiff.istSchiffGesunken())
					{
						seetuechtigeSchiffe++;
					}
			}


		return seetuechtigeSchiffe;
	}

//Fuer saemtliche Schiffe der Flotte wird ueberprueft, ob sich diese auf dem Zielfeld befunden haben, in diesem Fall wird der Treffer abgehandelt
bool Spieler::pruefeTreffer(Feld zielFeld)
	{
		bool treffer = false;
		for (auto& schiff : flotte)
			{
				//Unter Wasser weht kein Wind, deswegen waere die Windberechnung fuer gesunkene Schiffe ueberfluessig
				if (!schiff.istSchiffGesunken())
					{
						if (schiff.pruefeTreffer(zielFeld))
							{
								//Wurde ein Schiff getroffen, muessen die anderen nicht weiter geprueft werden
								treffer = true;
								break;
							}
					}
			}

		return treffer;
	}

void Spieler::spielfeldAktualisieren()
	{
		//Zunaechst muessen alle alten Schiffspositionen entfernt werden um Doppelte Auffuehrungen zu verhindern
		spielfeld.entferneFeldstatus(Feld::FeldStatus::Schiff);

		//Im Anschluss werden alle verbleibenden Schiffe auf dem Spielfeld verteilt
		for (auto schiff : flotte)
			{
				//Unter Wasser weht kein Wind, deswegen waere die Windberechnung fuer gesunkene Schiffe ueberfluessig
				if (!schiff.istSchiffGesunken())
					{
						//da bereits an anderer Stelle sichergestellt wurde, dass sowohl der Ankerplatz als auch jedes Feld
						//auf dem Spielfeld ein gueltiges Feld ist, eruebrigt sich eine weitere Ueberpruefung an dieser Stelle
						Feld& tempFeld = spielfeld.getFeldReference(schiff.getAnkerplatz());
						tempFeld.setStatus(Feld::FeldStatus::Schiff);
					}
			}
	}

bool Spieler::spielendePruefen()
	{
		bool hatVerloren = true;

		//Diese Funktion ist nun deutlich universeller, da ueber die Schiffe, nicht die Anzahl der Treffer
		//und die Anzahl der urspruenlich platzierten Schiffe gerechnet wird, somit sind unterschiedliche Flottengroessen
		//kein Problem mehr

		//Ein grosser Unterschied ist, dass sich die Logik nun invertiert hat - jeder Spieler kann nun nur noch pruefen, ob er verloren
		//hat, da es keine Moeglichkeit gibt die Flotte des Gegners zu pruefen
		if(getSeetuechtigeSchiffsanzahl() > 0)
			{
				//solange noch ein Schiff aktiv ist, hat der fragliche Spieler noch nicht verloren
				hatVerloren = false;
			}

		return hatVerloren;
	}
