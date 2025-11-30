package neetcode150;

// Valid Anagram 242
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

public class ValidAnagram {

    public static boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        int[] count = new int[26];
        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i) - 'a']++;
            count[t.charAt(i) - 'a']--;
        }
        for (int c : count) {
            if (c != 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        String s1 = "cat";
        String s2 = "tac";

        System.out.println(isAnagram(s1, s2));
    }
}
