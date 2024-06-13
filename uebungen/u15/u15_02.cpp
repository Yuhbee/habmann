#include <iostream>
#include <stack>
#include <cstdlib>

int main()
{
    std::stack<char> stkZeichen; // einen leeren Stack deklarieren
    char chZeichen;              // Hilfsvariable

    system("clear"); // Bildschirm loeschen
    std::cout << "\n\n   Bitte geben Sie eine beliebige Anzahl von Zeichen ein (beenden Sie die Eingabe mit Enter):\n\n     ";

    // Zum Ueben der Stack-Technik: Eingabe per Zeichen und push
    while (std::cin.get(chZeichen) && chZeichen != '\n')
    {
        stkZeichen.push(chZeichen);
    }

    std::cout << "\n\n  Ausgabe der Buchstaben in umgekehrter Reihenfolge:\n\n     ";
    while (!stkZeichen.empty())
    {
        std::cout << stkZeichen.top();
        stkZeichen.pop();
    }

    std::cout << "\n\n\n";

    return 0;
}
