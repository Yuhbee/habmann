#include <iostream>

class Dint {
private:
    double dval;
    int ival;

public:
    // Konstruktoren
    Dint() : dval(0.0), ival(0) {}
    Dint(double d, int i) : dval(d), ival(i) {}

    // Destruktor
    ~Dint() {}

    // Methode zum Addieren eines Dint-Objekts
    void addiere(const Dint& var) {
        this->dval += var.dval;
        this->ival += var.ival;
    }

    // Überladung des + Operators
    Dint operator+(const Dint& other) const {
        Dint result;
        result.dval = this->dval + other.dval;
        result.ival = this->ival + other.ival;
        return result;
    }

    // Methode zum Anzeigen der Werte
    void display() const {
        std::cout << "double: " << dval << "  int: " << ival << std::endl;
    }

    // Spezifische Anzeige-Methode für das Beispiel
    void displayDetailed(const std::string& varName) const {
        std::cout << varName << ": double: " << dval << "  int: " << ival << std::endl;
    }
};

int main() {
    Dint var1(1.0, 3);
    Dint var2(2.5, 10);

    std::cout << "Var1: ";
    var1.displayDetailed("Var1");

    std::cout << "Var2: ";
    var2.displayDetailed("Var2");

    // Verwendung der addiere Methode
    var1.addiere(var2);
    std::cout << "\nAddiere var2 zu var1\n";
    std::cout << "Var1: ";
    var1.displayDetailed("Var1");

    std::cout << "Var2: ";
    var2.displayDetailed("Var2");

    return 0;
}

