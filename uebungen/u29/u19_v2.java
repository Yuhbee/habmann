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

// Basisklasse 3D-Form
abstract class Form3D extends Form {
    public Form3D(String farbe, boolean gefuellt) {
        super(farbe, gefuellt);
    }

    // Methode zur Berechnung des Volumens
    public abstract double berechneVolumen();
}

// Klasse Kugel
class Kugel extends Form3D {
    private double radius;

    public Kugel(String farbe, boolean gefuellt, double radius) {
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
        return 4 * Math.PI * radius * radius;
    }

    @Override
    public double berechneVolumen() {
        return (4 / 3.0) * Math.PI * Math.pow(radius, 3);
    }

    @Override
    public double berechneUmfang() {
        return 2 * Math.PI * radius;
    }
}

// Klasse Pyramide
class Pyramide extends Form3D {
    private double grundflaeche;
    private double hoehe;

    public Pyramide(String farbe, boolean gefuellt, double grundflaeche, double hoehe) {
        super(farbe, gefuellt);
        this.grundflaeche = grundflaeche;
        this.hoehe = hoehe;
    }

    public double getGrundflaeche() {
        return grundflaeche;
    }

    public void setGrundflaeche(double grundflaeche) {
        this.grundflaeche = grundflaeche;
    }

    public double getHoehe() {
        return hoehe;
    }

    public void setHoehe(double hoehe) {
        this.hoehe = hoehe;
    }

    @Override
    public double berechneFlaeche() {
        // Vereinfachung: Berechnung der Oberfläche einer quadratischen Pyramide
        double seitenkante = Math.sqrt(grundflaeche);
        double seitenhoehe = Math.sqrt((seitenkante / 2) * (seitenkante / 2) + hoehe * hoehe);
        return grundflaeche + 2 * seitenkante * seitenhoehe;
    }

    @Override
    public double berechneVolumen() {
        return (1 / 3.0) * grundflaeche * hoehe;
    }

    @Override
    public double berechneUmfang() {
        // Umfang ist hier nicht definiert, Rückgabe von 0 oder einer sinnvollen Standardzahl
        return 0;
    }
}

// Klasse Quader
class Quader extends Form3D {
    private double breite;
    private double hoehe;
    private double tiefe;

    public Quader(String farbe, boolean gefuellt, double breite, double hoehe, double tiefe) {
        super(farbe, gefuellt);
        this.breite = breite;
        this.hoehe = hoehe;
        this.tiefe = tiefe;
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

    public double getTiefe() {
        return tiefe;
    }

    public void setTiefe(double tiefe) {
        this.tiefe = tiefe;
    }

    @Override
    public double berechneFlaeche() {
        return 2 * (breite * hoehe + hoehe * tiefe + tiefe * breite);
    }

    @Override
    public double berechneVolumen() {
        return breite * hoehe * tiefe;
    }

    @Override
    public double berechneUmfang() {
        // Umfang ist hier nicht definiert, Rückgabe von 0 oder einer sinnvollen Standardzahl
        return 0;
    }
}

// Hauptklasse zum Testen der Funktionen
public class u19_v2 {
    public static void main(String[] args) {
        // Test der 2D-Formen
        Kreis kreis = new Kreis("Rot", true, 5.0);
        System.out.println("Kreis Flaeche: " + kreis.berechneFlaeche());
        System.out.println("Kreis Umfang: " + kreis.berechneUmfang());

        Dreieck dreieck = new Dreieck("Blau", false, 3.0, 4.0);
        System.out.println("Dreieck Flaeche: " + dreieck.berechneFlaeche());
        System.out.println("Dreieck Umfang: " + dreieck.berechneUmfang());

        Rechteck rechteck = new Rechteck("Gruen", true, 4.0, 6.0);
        System.out.println("Rechteck Flaeche: " + rechteck.berechneFlaeche());
        System.out.println("Rechteck Umfang: " + rechteck.berechneUmfang());

        // Test der 3D-Formen
        Kugel kugel = new Kugel("Gelb", true, 5.0);
        System.out.println("Kugel Flaeche: " + kugel.berechneFlaeche());
        System.out.println("Kugel Volumen: " + kugel.berechneVolumen());

        Pyramide pyramide = new Pyramide("Violett", false, 25.0, 10.0);
        System.out.println("Pyramide Flaeche: " + pyramide.berechneFlaeche());
        System.out.println("Pyramide Volumen: " + pyramide.berechneVolumen());

        Quader quader = new Quader("Orange", true, 4.0, 6.0, 8.0);
        System.out.println("Quader Flaeche: " + quader.berechneFlaeche());
        System.out.println("Quader Volumen: " + quader.berechneVolumen());
    }
}
