#include <bits/stdc++.h>
using namespace std;

int numDecodings(string s)
{
    int n = s.length();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = (s[0] == '0') ? 0 : 1;

    for (int i = 2; i <= n; i++)
    {
        int oneDigit = s[i - 1] - '0';
        int twoDigits = stoi(s.substr(i - 2, 2));

        if (oneDigit >= 1)
            dp[i] += dp[i - 1];

        if (twoDigits >= 10 && twoDigits <= 26)
            dp[i] += dp[i - 2];
    }

    return dp[n];
}
}

int main()
{

    /*
    You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:

    "1" -> 'A'

    "2" -> 'B'

    ...

    "25" -> 'Y'

    "26" -> 'Z'

    However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes ("2" and "5" vs "25").

    For example, "11106" can be decoded into:

    "AAJF" with the grouping (1, 1, 10, 6)
    "KJF" with the grouping (11, 10, 6)
    The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).
    Note: there may be strings that are impossible to decode.

    Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return 0.

    The test cases are generated so that the answer fits in a 32-bit integer.
    */
    string s = "226";

    cout << numDecodings(s) << endl;
    return 0;
}