// Modul3/U14_string.cpp
#include <iostream>
#include <string>

int main() 
{
  std::string str1 = "String";
  std::string str2 {"String 2"};
  std::string str3 {};  // Leer
  std::string str4;     // Leer
  str1.append(" 1");    // anhaengen

  // Zuweisung und Konkatenierung
  str2 = str1 + (" und ") + str2;

  // Ausgabe über std::cout
  std::cout << "str1: " << str1 << '\n';
  std::cout << "str2: " << str2 << '\n';

  // Komplette Zeile einlesen
  std::cout << "String eingeben: ";
  std::getline(std::cin, str3);  // Zeile einlesen
  std::cout << "Ihre Eingabe: " << str3 << '\n';

  // String str1 durch einen Teil von str3 ersetzen
  // Ab dem Index 1 drei Zeichen aus str3
  str1.assign(str3, 1, 3);
  std::cout << "str1: " << str1 << "\n";

  // Anzahl der Zeichen im String ausgeben
  std::cout << "Zeichen in str1: " << str1.size() << '\n';

  // Maximal mögliche Größe
  std::cout << "Max. Zeichen für str1: ";
  std::cout << str1.max_size() << '\n';

  return 0;
}
