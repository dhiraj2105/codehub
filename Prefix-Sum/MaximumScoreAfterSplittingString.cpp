#include <bits/stdc++.h>
using namespace std;

// Brute force method : check every split, count zeros and ones
int maxScore_BruteForce(string s)
{
    // start with zero score
    int maxScore = 0;

    // try every split position
    for (int i = 1; i < s.length(); i++)
    {
        int leftZeros = 0; // left substring to count 0
        int rightOnes = 0; // right substring to count 1

        // count 0 in left part
        for (int j = 0; j < i; j++)
        {
            if (s[j] == '0')
            {
                leftZeros++;
            }
        }
        // count 1 in right part
        for (int j = i; j < s.length(); j++)
        {
            if (s[j] == '1')
            {
                rightOnes++;
            }
        }

        // Score
        int score = leftZeros + rightOnes;

        // update max score
        maxScore = max(maxScore, score);
    }
    return maxScore;
}

//  Optimized method : Only scan string once
int maxScore(string s)
{
    int totalOnes = 0; // total number of 1 in whole string
    int leftZeros = 0; // zeros seen so far in left part
    int maxScore = 0;  // max score found so far

    // first count all 1 in string
    for (char c : s)
    {
        if (c == '1')
        {
            totalOnes++;
        }
    }

    int rightOnes = totalOnes;

    // Traverse string and calcualte score at each split
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == '0')
        {
            leftZeros++; // if 0 then increase leftZeros count
        }
        else
        {
            rightOnes--; // if 1 then it moves from right to left
        }

        // Score
        int score = leftZeros + rightOnes;

        // update max score
        maxScore = max(maxScore, score);
    }

    return maxScore;
}

int main()
{
    /*
    Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

    The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.
    */
    string s = "011101";

    cout << "Max Score by Brute Force Method : " << maxScore_BruteForce(s) << endl;

    cout << "Max Score by optimized method : " << maxScore(s);

    return 0;
}