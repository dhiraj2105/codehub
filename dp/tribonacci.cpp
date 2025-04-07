#include <bits/stdc++.h>
using namespace std;

int tribonacci(int n)
{
    if (n == 2 || n == 1)
    {
        return 1;
    }
    else if (n == 0)
    {
        return 0;
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
}

int main()
{
    int n = 5;

    cout << "Tribonacci number at position " << n << " is " << tribonacci(n) << endl;

    return 0;
}