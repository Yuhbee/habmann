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

int Hilfsklasse::getIntOfChar(char charToConvert)
    {
        int tempInt = 0;
        switch (charToConvert)
            {
                case  'A':
                    tempInt = 0;
                    break;
                case  'B':
                    tempInt = 1;
                    break;
                case  'C':
                    tempInt = 2;
                    break;
                case  'D':
                    tempInt = 3;
                    break;
                case  'E':
                    tempInt = 4;
                    break;
                case  'F':
                    tempInt = 5;
                    break;
                case  'G':
                    tempInt = 6;
                    break;
                case  'H':
                    tempInt = 7;
                    break;
                case  'I':
                    tempInt = 8;
                    break;
                case  'J':
                    tempInt = 9;
                    break;
                default:
                    tempInt = 0;
                    break;
            }

        return tempInt;
    }
