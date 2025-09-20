import java.util.Arrays;

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
}

public class Problems {

    public static void main(String[] args) {
        String str1 = "madam";
        String str2 = "adamm";

        MyString myStr = new MyString();

        myStr.palindromeCheck(str1);
        myStr.anagramCheck(str1, str2);
    }
}
