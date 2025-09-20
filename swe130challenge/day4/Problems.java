import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class MyString {

    void palindromeCheck(String str) {
        // compare characters from both ends, moving towards the center of string
        for (int i = 0; i < str.length() / 2; i++) {
            if (str.charAt(i) != str.charAt(str.length() - i - 1)) {
                System.out.println(str + " is not a palindrome");
                return;
            }
        }
        System.out.println(str + " is a palindrome");
    }

    void anagramCheck(String str1, String str2) {
        // First of all, check if lengths of both strings are equal
        if (str1.length() != str2.length()) {
            System.out.println("Not anagrams");
            return;
        }
        // convert strings to lower case and remove spaces for case
        str1 = str1.toLowerCase().replaceAll("\\s", "");
        str2 = str2.toLowerCase().replaceAll("\\s", "");

        // sort the strings
        // for that we have to convert string -> char arrays
        char[] arr1 = str1.toCharArray();
        char[] arr2 = str2.toCharArray();

        Arrays.sort(arr1);
        Arrays.sort(arr2);

        // compare both sorted arrays
        boolean res = Arrays.equals(arr1, arr2);

        // return
        if (res) {
            System.out.println("Strings are anagram");
        } else {
            System.out.println("Strings are not anagram");
        }
    }

    void vowelAndConsonants(String str) {
        int vowelCount = 0;
        int consonantCount = 0;

        str = str.toLowerCase();

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (ch >= 'a' && ch <= 'z') { // check if character is an alphabet
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    vowelCount++;
                } else {
                    consonantCount++;
                }
            }
        }

        System.out.println("Number of vowels: " + vowelCount);
        System.out.println("Number of consonants: " + consonantCount);
    }

    void removeDuplicates(String str) {
        // creates a set to keep track of characters we have already seen
        Set<Character> seen = new HashSet<>();

        // create a new result string
        // we will use stringbuilder, coz strings are not mutable and stringbuilders are
        StringBuilder res = new StringBuilder();

        // convert input string to char array
        char[] arr = str.toCharArray();

        for (int i = 0; i < arr.length; i++) {
            // if char is not already in set
            if (!seen.contains(arr[i])) {
                seen.add(arr[i]);
                res.append(arr[i]);
            }
        }

        System.out.println("Strinng after removing duplicates : " + res.toString());
    }

    void reverseWords(String str) {
        String[] wordsArr = str.split("\\s+");

        StringBuilder res = new StringBuilder();

        for (int i = wordsArr.length - 1; i >= 0; i--) {
            res.append(wordsArr[i]);
            // add space between words but not after last word
            if (i != 0) {
                res.append(" ");
            }
        }
        System.out.println("Reversed words: " + res.toString());
    }
}

public class Problems {

    public static void main(String[] args) {
        String str1 = "madam";
        String str2 = "adamm";
        String str = "This is a String";

        MyString myStr = new MyString();

        myStr.palindromeCheck(str1);
        myStr.anagramCheck(str1, str2);
        myStr.vowelAndConsonants(str1);
        myStr.removeDuplicates(str1);
        myStr.reverseWords(str);
    }
}
