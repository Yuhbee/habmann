// Basisklasse Form
abstract class Form {
    private String farbe;
    private boolean gefuellt;

    public Form(String farbe, boolean gefuellt) {
        this.farbe = farbe;
        this.gefuellt = gefuellt;
    }

    public String getFarbe() {
        return farbe;
    }

    public void setFarbe(String farbe) {
        this.farbe = farbe;
    }

    public boolean isGefuellt() {
        return gefuellt;
    }

    public void setGefuellt(boolean gefuellt) {
        this.gefuellt = gefuellt;
    }

    // Methode zur Berechnung der Flaeche
    public abstract double berechneFlaeche();

    // Methode zur Berechnung des Umfangs
    public abstract double berechneUmfang();
}

// Klasse Kreis
class Kreis extends Form {
    private double radius;

    public Kreis(String farbe, boolean gefuellt, double radius) {
        super(farbe, gefuellt);
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    @Override
    public double berechneFlaeche() {
        return Math.PI * radius * radius;
    }

    @Override
    public double berechneUmfang() {
        return 2 * Math.PI * radius;
    }
}

// Klasse Dreieck
class Dreieck extends Form {
    private double seiteA;
    private double seiteB;

    public Dreieck(String farbe, boolean gefuellt, double seiteA, double seiteB) {
        super(farbe, gefuellt);
        this.seiteA = seiteA;
        this.seiteB = seiteB;
    }

    public double getSeiteA() {
        return seiteA;
    }

    public void setSeiteA(double seiteA) {
        this.seiteA = seiteA;
    }

    public double getSeiteB() {
        return seiteB;
    }

    public void setSeiteB(double seiteB) {
        this.seiteB = seiteB;
    }

    @Override
    public double berechneFlaeche() {
        return 0.5 * seiteA * seiteB;
    }

    @Override
    public double berechneUmfang() {
        double hypotenuse = Math.sqrt(seiteA * seiteA + seiteB * seiteB);
        return seiteA + seiteB + hypotenuse;
    }
}

// Klasse Rechteck
class Rechteck extends Form {
    private double breite;
    private double hoehe;

    public Rechteck(String farbe, boolean gefuellt, double breite, double hoehe) {
        super(farbe, gefuellt);
        this.breite = breite;
        this.hoehe = hoehe;
    }

    public double getBreite() {
        return breite;
    }

    public void setBreite(double breite) {
        this.breite = breite;
    }

    public double getHoehe() {
        return hoehe;
    }

    public void setHoehe(double hoehe) {
        this.hoehe = hoehe;
    }

    @Override
    public double berechneFlaeche() {
        return breite * hoehe;
    }

    @Override
    public double berechneUmfang() {
        return 2 * (breite + hoehe);
    }
}

// Hauptklasse zum Testen der Funktionen
public class u29 {
    public static void main(String[] args) {
        // Test des Kreises
        Kreis kreis = new Kreis("Rot", true, 5.0);
        System.out.println("Kreis Flaeche: " + kreis.berechneFlaeche());
        System.out.println("Kreis Umfang: " + kreis.berechneUmfang());

        // Test des Dreiecks
        Dreieck dreieck = new Dreieck("Blau", false, 3.0, 4.0);
        System.out.println("Dreieck Flaeche: " + dreieck.berechneFlaeche());
        System.out.println("Dreieck Umfang: " + dreieck.berechneUmfang());

        // Test des Rechtecks
        Rechteck rechteck = new Rechteck("Gruen", true, 4.0, 6.0);
        System.out.println("Rechteck Flaeche: " + rechteck.berechneFlaeche());
        System.out.println("Rechteck Umfang: " + rechteck.berechneUmfang());
    }
}
