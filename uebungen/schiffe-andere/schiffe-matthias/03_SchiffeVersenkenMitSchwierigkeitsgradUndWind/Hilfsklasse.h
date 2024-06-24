#ifndef Hilfsklasse_H
#define Hilfsklasse_H

//Wie der Name schon sagt, eine Reine Hilfsklasse die nuetzliche Funktionen enthaelt, die nicht direkt einer der Klassen zuzuordnen sind
class Hilfsklasse
    {
        public:
            enum class Windrichtung { Windstill, Nord, Ost, Sued, West };
            //Diese Funktionen sind static - somit sind sie benutzbar ohne ein Objekt der Klasse Hilfsklasse anlegen zu muessen
            static char getCharOfInt(int intToConvert);
            //Das Gegenstueck der oberen Funktion, fuer die Windberechnung wird es nun notwendig, auch aus der Spaltenbezeichnung eine Zahl zu erhalten
            static int getIntOfChar(char charToConvert);
    };

#endif