public class u27 {
    public static void main(String[] args) {
        String text = "Java ist eine tolle Programmiersprache.";

        int kleinbuchstabenZaehler = 0;
        int grossbuchstabenZaehler = 0;
        int leerzeichenZaehler     = 0;
        int andereZeichenZaehler   = 0;

        // Konvertierung des Strings in ein Zeichenarray
        char[] zeichenArray = text.toCharArray();

        for (char zeichen : zeichenArray) {
            if (Character.isLowerCase(zeichen)) {
                kleinbuchstabenZaehler++;
            } else if (Character.isUpperCase(zeichen)) {
                grossbuchstabenZaehler++;
            } else if (Character.isWhitespace(zeichen)) {
                leerzeichenZaehler++;
            } else {
                andereZeichenZaehler++;
            }
        }

        System.out.println("Anzahl der Kleinbuchstaben: " + kleinbuchstabenZaehler);
        System.out.println("Anzahl der Großbuchstaben:  " + grossbuchstabenZaehler);
        System.out.println("Anzahl der Leerzeichen:     " + leerzeichenZaehler);
        System.out.println("Anzahl der anderen Zeichen: " + andereZeichenZaehler);
    }
}
