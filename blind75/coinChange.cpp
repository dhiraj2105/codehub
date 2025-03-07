#include <bits/stdc++.h>
using namespace std;
int coinChange(vector<int> &coins, int amount)
{
    // Check edge case
    if (amount < 1)
        return 0;

    // Create DP array
    vector<int> minCoinsDP(amount + 1, INT_MAX);

    minCoinsDP[0] = 0; // Base case: 0 amount requires 0 coins

    for (int i = 1; i <= amount; i++)
    {
        // Try each coin
        for (int coin : coins)
        {
            if (coin <= i && minCoinsDP[i - coin] != INT_MAX)
            {
                minCoinsDP[i] = min(minCoinsDP[i], 1 + minCoinsDP[i - coin]);
            }
        }
    }

    return minCoinsDP[amount] == INT_MAX ? -1 : minCoinsDP[amount];
}
int main()
{
    /*
    You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

    Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

    You may assume that you have an infinite number of each kind of coin.
    */
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << coinChange(coins, amount) << endl;

    return 0;
}