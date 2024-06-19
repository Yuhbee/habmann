import java.util.Scanner;

public class gibmireina {
    public static void main(String[] args) {

        System.out.print("\n\n\n Bitte geben Sie ein 'a' ein: ");

        Scanner sGibMirEinaScanner = new Scanner(System.in);
        String sGibMirEina = sGibMirEinaScanner.nextLine();
        System.out.print("\n eingabe: " + sGibMirEina + "\n  ");

        // Hier holen wir das erste Zeichen der Eingabe
        char dasA = sGibMirEina.charAt(0);

        System.out.print("\n\n\n Sie haben ein: " + dasA + "\n\n eingegeben!\n\n ");

        sGibMirEinaScanner.close();
    }
}
