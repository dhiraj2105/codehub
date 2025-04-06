#include <bits/stdc++.h>
using namespace std;

// Function to calculate Fibonacci using the normal recursive approach
int fib(int num)
{
    if (num <= 1)
    {
        return num;
    }

    // Otherwise, calculate Fibonacci by calling the function recursively for num-1 and num-2
    return fib(num - 1) + fib(num - 2);
}

// Function to calculate Fibonacci using Dynamic Programming (Memoization) | Top-Down approach
int fibdp(int num, vector<int> &dp)
{
    if (num <= 1)
    {
        return num;
    }

    // If this Fibonacci value has been already computed, return it from the dp table (memoization)
    if (dp[num] != 0) // Only compute if it hasn't been computed before
        return dp[num];

    // Otherwise, calculate it by calling the function recursively and store the result in dp[num]
    dp[num] = fibdp(num - 1, dp) + fibdp(num - 2, dp);

    return dp[num];
}

// Function to calculate Fibonacci using Dynamic Programming | Bottom-Up approach (Tabulation)
int fibDPbu(int num)
{
    if (num <= 1)
    {
        return num;
    }

    // Create a dp array of size num+1 initialized to 0, to store Fibonacci values up to num
    vector<int> dp(num + 1, 0);

    // Set the base values for Fibonacci: F(0) = 0, F(1) = 1
    dp[0] = 0;
    dp[1] = 1;

    // Calculate Fibonacci for each number starting from 2 to num, by using previously computed values
    for (int i = 2; i <= num; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2]; // Fibonacci number is the sum of the two previous Fibonacci numbers
    }

    return dp[num];
}

int main()
{
    int n = 7;

    // cout << "The fibonacci of " << n << " is : " << fib(n) << endl;

    // vector<int> dp(n + 1, 0);
    // cout << "The fibonacci of " << n << " is : " << fibdp(n, dp) << endl;

    cout << "The fibonacci of " << n << " is : " << fibDPbu(n) << endl;

    return 0;
}