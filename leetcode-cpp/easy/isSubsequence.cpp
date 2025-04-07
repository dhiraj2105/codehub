#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t)
{
    int sPointer = 0;
    int tPointer = 0;
    while (tPointer < t.length())
    {
        if (s[sPointer] == t[tPointer])
        {
            sPointer++;
        }
        tPointer++;
    }
    return sPointer == s.length();
}

int main()
{
    /*
    Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

    A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
    */

    string s = "abc";
    string t = "ahbgdc";

    cout << boolalpha << isSubsequence(s, t);

    return 0;
}