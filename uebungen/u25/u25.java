import java.util.Scanner;

public class u25
{
    public static void main(String[] args)
    {
        // Variablen Deklarieren
        double dRechteckBreite;
        double dRechteckHoehe;
        double dRechteckUmfang;
        double dRechteckFlaeche;

        // EingabeScanner-Instanz erstellen
        java.util.Scanner dScanner = new Scanner(System.in);

        // Programm Ausgabe
        System.out.print("\n\n Rechteck-Berechnung: \n");

        // Eingabe der Breite des Rechtecks
        System.out.print(" Bitte die Breite des Rechtecks eingeben: ");
        dRechteckBreite = dScanner.nextDouble();
        System.out.println();

        // Eingabe der Hoehe des Rechtecks
        System.out.print(" Bitte die Breite des Rechtecks eingeben: ");
        dRechteckHoehe = dScanner.nextDouble();
        System.out.println();

        // EingabeScanner-Instanz schliessen
        dScanner.close();

        // Berechne den Umfang des Rechecks
        dRechteckUmfang = ( dRechteckBreite + dRechteckHoehe) * 2;
        // Berechne die Flaeche des Dreiecks
        dRechteckFlaeche = ( dRechteckBreite * dRechteckHoehe);

        //Ausgabe
        System.out.println("\n Der Umfang des Rechtecks beträgt: " + dRechteckUmfang);
        System.out.println("\n Die Fläche des Rechtecks beträgt: " + dRechteckFlaeche);
        System.out.println();
    }
}
