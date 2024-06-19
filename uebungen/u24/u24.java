import java.util.Scanner;

public class u24 {
    // Globale Variable
    int iGlobaleVariable = 10;

    // Statische Variable
    static int iStatischeVariable = 20;

    public static void main(String[] args) {
        // Lokale Variable
        int iLokaleVariable = 30;

        // Eingabe vom Benutzer
        Scanner scanner = new Scanner(System.in);
        System.out.print("Bitte geben Sie Ihren Namen ein: ");
        String sName = scanner.nextLine();

        // Ausgabe
        System.out.println("Hallo " + sName + "!");
        System.out.println("Lokale Variable: " + iLokaleVariable);
        System.out.println("Statische Variable: " + iStatischeVariable);

        // Erstellen eines Objekts, um auf die globale Variable zuzugreifen
        u24 hauptprogramm = new u24();
        System.out.println("Globale Variable: " + hauptprogramm.iGlobaleVariable);

        scanner.close();
    }
}
