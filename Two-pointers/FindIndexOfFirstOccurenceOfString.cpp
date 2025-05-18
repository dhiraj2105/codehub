#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle)
{
    int n = haystack.size(), m = needle.size();
    if (m == 0)
        return 0;

    for (int i = 0; i <= n - m; ++i)
    {
        int j = 0;
        while (j < m && haystack[i + j] == needle[j])
        {
            ++j;
        }
        if (j == m)
            return i;
    }
    return -1;
}

int main()
{
    /*
        Given two strings needle and haystack, return the index of first occurence of needle in haystack, or -1 if needle is not part of haystack
    */
    std::string haystack = "sadbutsad";
    std::string needle = "sad";

    int res = strStr(haystack, needle);

    if (res == -1)
    {
        cout << "String is not present";
    }
    else
    {
        cout << "String is present at index : " << res;
    }

    return 0;
}