package swe130challenge.day4;

public class Problems {
    /*
     * Palindrome check
     * Anagram check
     * Count vowels & consonants
     * Remove duplicates from a string
     * Find first non-repeating character
     * Reverse a string
     * Reverse words in a sentence
     * Convert sentence to Title Case
     */
    static void palindromeCheck(String str) {
        // compare characters from both ends, moving towards the center of string
        for (int i = 0; i < str.length() / 2; i++) {
            if (str.charAt(i) != str.charAt(str.length() - i - 1)) {
                System.out.println(str + " is not a palindrome");
                return;
            }
        }
        System.out.println(str + " is a palindrome");
    }

    public static void main(String[] args) {
        String str = "madam";

        palindromeCheck(str);
    }
}
