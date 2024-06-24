#include "Hilfsklasse.h"

char Hilfsklasse::getCharOfInt(int intToConvert)
    {
        char tempChar = ' ';
        switch (intToConvert)
            {
                case 0:
                    tempChar = 'A';
                    break;
                case 1:
                    tempChar = 'B';
                    break;
                case 2:
                    tempChar = 'C';
                    break;
                case 3:
                    tempChar = 'D';
                    break;
                case 4:
                    tempChar = 'E';
                    break;
                case 5:
                    tempChar = 'F';
                    break;
                case 6:
                    tempChar = 'G';
                    break;
                case 7:
                    tempChar = 'H';
                    break;
                case 8:
                    tempChar = 'I';
                    break;
                case 9:
                    tempChar = 'J';
                    break;
                default:
                    tempChar = '?';
                    break;
            }

        return tempChar;
    }
