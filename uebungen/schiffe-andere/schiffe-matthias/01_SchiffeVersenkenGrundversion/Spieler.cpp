#include "Spieler.h"

//In der vorliegenden Ausbaustufe hat die Flotte noch keine Bedeutung, aber hier werden die Schiffe gesammelt
void Spieler::insertSchiff(Schiff neuesSchiff)
	{
		flotte.push_back(neuesSchiff);
	}

//Der Spieler selbst hat nur einen leeren Standardkonstruktor, aber statt eines Konstruktors der diese Werte setzt
//wird eine Funktion definiert, um auch ein mehrfaches Spielen zu ermoeglichen. 
//Sollte ein Konstruktor mit diesen Werten gewuenscht sein, kann auch einfach diese Init Funktion aufgerufen werden
void Spieler::initSpieler(int feldBreite, int zielFeldBreite)
	{
		spielfeld.initSpielfeld(feldBreite);
		zielfeld.initSpielfeld(zielFeldBreite);

		flotte.clear();
		anzahlSchiffe = feldBreite;
	}

bool Spieler::spielendePruefen()
	{
		bool hatGewonnen = false;

		//Achtung - diese Variante funktioniert nur in dem vorliegenden Code, da die Anzahl der Schiffe momentan
		//identisch mit der Spielfeldgroesse ist, sollte sich das aendern muss entweder auf anzahlSchiffe zugegriffen
		//werden, wenn die Anzahl der Schiffe identisch mit der des Gegners ist oder die Anzahl der zu versenkenden Schiffe
		//muss anderweitig festgehalten werden.
		if (zielfeld.getFeldStatusCount(Feld::FeldStatus::Treffer) == zielfeld.getSpielfeldGroesse())
			{
				hatGewonnen = true;
			}

		return hatGewonnen;
	}
