#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string> &wordDict)
{
    // Base case: If the string is empty, it can be segmented.
    if (s.empty())
    {
        return true;
    }

    // Iterate over each word in the dictionary.
    for (const auto &word : wordDict)
    {
        // Check if the string starts with the current word.
        if (s.find(word) == 0)
        {
            // Recursively check the remaining part of the string.
            if (wordBreak(s.substr(word.size()), wordDict))
            {
                return true;
            }
        }
    }

    // If no word matches, return false.
    return false;
}

int main()
{
    /*
    Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

    Note that the same word in the dictionary may be reused multiple times in the segmentation.
    */
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};

    cout << wordBreak(s, wordDict) << endl;
    return 0;
}