#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
}
int main()
{

    /*
    Given two strings s and t, return true if t is an anagram of s, and false otherwise.
    */
    string s = "anagram";
    string t = "nagaram";
    cout << boolalpha << isAnagram(s, t) << endl;
    return 0;
}