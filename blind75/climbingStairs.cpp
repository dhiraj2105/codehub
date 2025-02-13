#include <bits/stdc++.h>
using namespace std;

int climbingStairs(int n)
{
    if (n == 1)
        return 1;

    int dp[n + 1];
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}
int main()
{
    /*
    You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
    */
    int n;

    cout << climbingStairs(n);
    return 0;
}