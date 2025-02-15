#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    int n = s.length();
    int left = 0, right = n - 1;

    while (left < right)
    {
        if (!isalnum(s[left]))
        {
            left++;
        }
        else if (!isalnum(s[right]))
        {
            right--;
        }
        else if (tolower(s[left]) != tolower(s[right]))
        {
            return false;
        }
        else
        {
            left++;
            right--;
        }
    }
    return true;
}

int main()
{
    /*
    A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
    Given a string s, return true if it is a palindrome, or false otherwise.
    */
    string s = "A man, a plan, a canal: Panama";

    cout << isPalindrome(s) << endl;
    return 0;
}