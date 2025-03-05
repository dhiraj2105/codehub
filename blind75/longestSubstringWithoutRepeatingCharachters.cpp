#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> charset;

    int maxLength = 0;
    int left = 0;

    for (int right = 0; right < s.size(); right++)
    {
        while (charset.find(s[right]) != charset.end())
        {
            charset.erase(s[left]);
            left++;
        }
        charset.insert(s[right]);
        maxLength = max(maxLength, right - left + 1);
    }
    return maxLength;
}

int main()
{
    string s = "abcabcbb";

    cout << lengthOfLongestSubstring(s);
    return 0;
}