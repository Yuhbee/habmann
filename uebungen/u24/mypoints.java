import java.awt.Point;

public class mypoints
{
    public static void main(String[] args)
    {
        // Erstellen eines Point-Objekts
        Point p1 = new Point(10, 20);

        // Ausgabe der x- und y-Koordinaten
        System.out.println("x: " + p1.x);
        System.out.println("y: " + p1.y);

        // Ändern der Koordinaten
        p1.setLocation(30, 40);
        System.out.println("Neuer Punkt: " + p1);

        // Berechnen der Distanz zu einem anderen Punkt
        Point p2 = new Point(50, 60);
        double distance = p1.distance(p2);
        System.out.println("Distanz zu p2: " + distance);
    }
}
