package swe130challenge.day4;

public class strings {

    public static void main(String[] args) {
        String str = "Hello, World!";
        System.out.println("Original String: " + str);

        // Convert to uppercase
        String upperStr = str.toUpperCase();
        System.out.println("Uppercase: " + upperStr);

        // Convert to lowercase
        String lowerStr = str.toLowerCase();
        System.out.println("Lowercase: " + lowerStr);

        // Get substring
        String subStr = str.substring(7, 12);
        System.out.println("Substring (7-12): " + subStr);

        // Replace characters
        String replacedStr = str.replace("World", "Java");
        System.out.println("Replaced String: " + replacedStr);

        // Trim whitespace
        String strWithSpaces = "   Hello, World!   ";
        String trimmedStr = strWithSpaces.trim();
        System.out.println("Trimmed String: '" + trimmedStr + "'");

        // Split string
        String[] words = str.split(", ");
        System.out.println("Split String:");
        for (String word : words) {
            System.out.println(word);
        }

        // Check if string contains a substring
        boolean containsHello = str.contains("Hello");
        System.out.println("Contains 'Hello': " + containsHello);

        // Get length of the string
        int length = str.length();
        System.out.println("Length of the string: " + length);

    }
}