// Aufgabe zur Modulpruefung 3_2
// Uwe Bauermann
// 20240617
// ----
// Ungarische Notation
// KEINE Umlaute in KOmmentaren
// 

#include <iostream>
#include <string>

using namespace std;

// Ich erstelle die Basisklasse Tier
class CTier
{
protected:
    // Name und Alter als Geschuetzte Attribute
    string msName; // m = Member einer Klasse, s = String
    int miAlter;   // m = Member einer Klasse, i = Integer

public:
    // Konstruktor mit Elementar-Uebergabe
    // Es wird ein Infotext ausgegben
    CTier(string sName, int iAlter) : msName(sName), miAlter(iAlter) {
        cout << "  CTier Konstruktor aufgerufen fuer " << msName << endl;
    }

    // Destruktor
    // Es wird ein Infotext ausgegben
    virtual ~CTier() {
        cout << "  CTier Destruktor aufgerufen fuer " << msName << endl;
    }

    // Methode vorstellen
    // Virtuell damit ich sie ueberschreiben kann (Danke an AI für den Tipp!)
    virtual void vorstellen()
    {
        cout << "  Ich bin ein Tier. Name: " << msName << ", Alter: " << miAlter << " Jahre." << endl;
    }

    // Methode lautGeben 
    // Virtuell damit ich sie ueberschreiben kann
    virtual void lautGeben()
    {
        cout << "  Tier macht ein Geraeusch." << endl;
    }
};

// Erstellen der Abgeleitete Klasse Vogel
class CVogel : public CTier
{
private:
    // Private Attribute
    int miFluegelspannweite;  // m = Member einer Klasse, i = Integer

public:
    // Konstruktor
    // Bildschirmausgabe direkt im Konstruktor definiert
    // Es wird ein Infotext ausgegben
    CVogel(string sName, int iAlter, int iFluegelspannweite)
        : CTier(sName, iAlter), miFluegelspannweite(iFluegelspannweite) {
        cout << "  CVogel Konstruktor aufgerufen fuer " << msName << endl;
    }

    // Destruktor
    // Es wird ein Infotext ausgegben
    ~CVogel() 
    {
        cout << "  CVogel Destruktor aufgerufen fuer " << msName << endl;
    }

    // Methode vorstellen (ueberschrieben)
    void vorstellen() override 
    {
        cout << "  Ich bin ein Vogel. Name: " << msName << ", Alter: " << miAlter
             << " Jahre, Fluegelspannweite: " << miFluegelspannweite << " cm." << endl;
    }

    // Methode lautGeben (ueberschrieben)
    // Gilt hier natuerlich nur fuer den Papagei
    void lautGeben() override 
    {
        cout << "  Vogel macht ein Kreischen." << endl;
    }
};

// Abgeleitete Klasse Saeugetier
class CSaeugetier : public CTier 
{
private:
    // Private Attribute
    string msFellfarbe;

public:
    // Konstruktor
    // Bildschirmausgabe direkt im Konstruktor definiert
    // Es wird ein Infotext ausgegben
    CSaeugetier(string sName, int iAlter, string sFellfarbe)
        : CTier(sName, iAlter), msFellfarbe(sFellfarbe) {
        cout << "  CSaeugetier Konstruktor aufgerufen fuer " << msName << endl;
    }

    // Destruktor
    // Es wird ein Infotext ausgegben
    ~CSaeugetier()
    {
        cout << "  CSaeugetier Destruktor aufgerufen fuer " << msName << endl;
    }

    // Methode vorstellen (ueberschrieben)
    void vorstellen() override 
    {
        cout << "  Ich bin ein Saeugetier. Name: " << msName << ", Alter: " << miAlter
             << " Jahre, Fellfarbe: " << msFellfarbe << "." << endl;
    }

    // Methode lautGeben (ueberschrieben)
    // gilt hier natuerlich nur fuer den Hund
    void lautGeben() override 
    {
        cout << "  Saeugetier macht ein Bellen." << endl;
    }
};

int main() 
{
    cout << "\n\n";
    // Erstelle Objekte der Klassen direkt
    // "Was macht das Tier" koennte man auch noch uebergeben.
    // heute aber nicht! ToDo: vielleicht im naechsten Leben
    CTier tier("Allgemeines Tier", 5);
    CVogel vogel("Papagei", 2, 30);
    CSaeugetier saeugeTier("Hund", 3, "Braun");

    // Rufe die vorstellen Methode auf
    tier.vorstellen();
    vogel.vorstellen();
    saeugeTier.vorstellen();

    // Rufe die lautGeben Methode auf
    tier.lautGeben();
    vogel.lautGeben();
    saeugeTier.lautGeben();

    cout << "\n\n";
    return 0;

    // Gut zu wissen:
    // Die Destruktoren werden immer am Ende des Gültigkeitsbereichs 
    // (Scope) der Objekte aufgerufen. 
    // Da meine Objekte am Ende der main-Funktion zerstört werden, 
    // erscheinen die Destruktor-Ausgaben nach dem \n\n.
    // !!!


}

