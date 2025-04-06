#include <bits/stdc++.h>
using namespace std;

int fib(int num)
{
    // This is the normal recusive solution
    if (num <= 1)
    {
        return num;
    }

    return fib(num - 1) + fib(num - 2);
}

int fibdp(int num, vector<int> &dp)
{
    // This is the solution with dp
    // TOP - DOWN approach | recusrion + memoization
    if (num <= 1)
    {
        return num;
    }

    dp[num] = fibdp(num - 1, dp) + fibdp(num - 2, dp);

    return dp[num];
}

int main()
{
    int n = 7;
    // cout << "The fibonacci of " << n << " is : " << fib(n) << endl;

    vector<int> dp(n + 1, 0);

    cout << "The fibonacci of " << n << " is : " << fibdp(n, dp) << endl;

    return 0;
}