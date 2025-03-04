#include <iostream>
#include <string>
using namespace std;

// Function to find the longest palindrome substring in a string
string longestPalindrome(string str)
{
    // If the string length is 1 or less, it's already a palindrome
    if (str.length() <= 1)
        return str;

    // Initialize the result variable to store the longest palindrome substring
    string LPS = "";

    // Loop through each character of the string starting from index 1
    for (int i = 1; i < str.length(); i++)
    {

        // Consider odd length palindrome, with 'i' as the center
        int low = i;
        int high = i;

        // Expand outwards as long as characters at the low and high indices match
        while (low >= 0 && high < str.length() && str[low] == str[high])
        {
            low--;
            high++;

            // Check if we've reached the boundaries of the string
            if (low == 1 || high == str.length())
                break;
        }

        // Extract the palindrome substring between indices (low + 1) and high
        string palindrome = str.substr(low + 1, high - low - 1);
        // If the palindrome length is greater than the current longest palindrome, update it
        if (palindrome.length() > LPS.length())
        {
            LPS = palindrome;
        }

        // Consider even length palindrome, with 'i' and 'i-1' as the center
        low = i - 1;
        high = i;

        // Expand outwards as long as characters at the low and high indices match
        while (low >= 0 && high < str.length() && str[low] == str[high])
        {
            low--;
            high++;

            // Check if we've reached the boundaries of the string
            if (low == -1 || high == str.length())
                break;
        }

        // Extract the palindrome substring between indices (low + 1) and high
        palindrome = str.substr(low + 1, high - low - 1);
        // If the palindrome length is greater than the current longest palindrome, update it
        if (palindrome.length() > LPS.length())
        {
            LPS = palindrome;
        }
    }

    // Return the longest palindrome substring found
    return LPS;
}

int main()
{
    string input = "babad";
    cout << "Longest Palindromic Substring: " << longestPalindrome(input) << endl;
    return 0;
}
