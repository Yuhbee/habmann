// Aufgabe Uebung 28
// 20240620, ub
// ----
// Ungarische Notation
// KEINE Umlaute in Kommentaren
//
//

import java.util.ArrayList;
import java.util.List;

public class u28 {
    public static void main(String[] args) {
        // Bildschirm löschen
        clearScreen();

        // Liste zur Verwaltung der Konten
        List<Konto> kontenListe = new ArrayList<>();

        // Beispielhafte Erstellung der Konten
        Konto k1 = new Konto("Hans");
        Konto k2 = new Konto("Peter", 500.0);
        Konto k3 = new Konto("Sabine", 1000.0, 200.0);

        // Konten zur Liste hinzufügen
        kontenListe.add(k1);
        kontenListe.add(k2);
        kontenListe.add(k3);

        // Anzeige der erstellten Konten
        zeigeKonten(kontenListe);

        k1.einzahlen(200);
        zeigeKonten(List.of(k1)); // zeigt einzelne Kontoinformationen

        boolean bErgebnis = k2.abheben(600);
        System.out.println("Abheben von 600 von Konto Peter: " + (bErgebnis ? "Erfolgreich" : "Fehlgeschlagen"));
        zeigeKonten(List.of(k2)); // zeigt einzelne Kontoinformationen

        bErgebnis = k3.abheben(1100);
        System.out.println("Abheben von 1100 von Konto Sabine: " + (bErgebnis ? "Erfolgreich" : "Fehlgeschlagen"));
        zeigeKonten(List.of(k3)); // zeigt einzelne Kontoinformationen
    }

    public static void clearScreen() {
        try {
            if (System.getProperty("os.name").contains("Windows")) {
                new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
            } else {
                System.out.print("\033[H\033[2J");  // Sogenannte ESCAPE-Sequenz!
                System.out.flush();
            }
        } catch (Exception e) {
            System.out.println("Fehler beim Löschen des Bildschirms.");
        }
    }

    public static void zeigeKonten(List<Konto> kontenListe) {
        System.out.println("+--------------------------+-------------+-----------------+");
        System.out.println("| Besitzer                 | Guthaben    | Ueberziehungsl. |");
        System.out.println("+--------------------------+-------------+-----------------+");

        for (Konto konto : kontenListe) {
            System.out.printf("| %-24s | %11.2f | %15.2f |\n", konto.getBesitzer(), konto.getGuthaben(), konto.getUeberziehungslimit());
        }

        System.out.println("+--------------------------+-------------+-----------------+\n");
    }
}

class Konto {
    private String sBesitzer; // owner
    private double dGuthaben; // balance
    private double dUeberziehungslimit; // overdrafts

    // Konstruktoren
    public Konto(String p_sBesitzer) {
        sBesitzer = p_sBesitzer;
        dGuthaben = 0.0;
        dUeberziehungslimit = 0.0;
    }

    public Konto(String p_sBesitzer, double p_dAnfangsguthaben) {
        sBesitzer = p_sBesitzer;
        dGuthaben = p_dAnfangsguthaben;
        dUeberziehungslimit = 0.0;
    }

    public Konto(String p_sBesitzer, double p_dAnfangsguthaben, double p_dUeberziehungslimit) {
        sBesitzer = p_sBesitzer;
        dGuthaben = p_dAnfangsguthaben;
        dUeberziehungslimit = p_dUeberziehungslimit;
    }

    // Methoden
    public String getBesitzer() { // getOwner
        return sBesitzer;
    }

    public double getGuthaben() { // getBalance
        return dGuthaben;
    }

    public double getUeberziehungslimit() { // getOverdrafts
        return dUeberziehungslimit;
    }

    public void einzahlen(double p_dBetrag) { // deposit
        if (p_dBetrag > 0) {
            dGuthaben += p_dBetrag;
            System.out.println("Einzahlung von " + p_dBetrag + " auf Konto " + sBesitzer + ": Erfolgreich");
        } else {
            System.out.println("Einzahlung von " + p_dBetrag + " auf Konto " + sBesitzer + ": Fehlgeschlagen");
        }
        System.out.println(); // Leerzeile
    }

    public boolean abheben(double p_dBetrag) { // withdraw
        if (p_dBetrag > 0 && dGuthaben + dUeberziehungslimit >= p_dBetrag) {
            dGuthaben -= p_dBetrag;
            return true;
        }
        return false;
    }
}
