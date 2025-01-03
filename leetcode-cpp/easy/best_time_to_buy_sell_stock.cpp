#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    if (n < 2)
    {
        return 0;
    }

    int buy = 0;
    int sell = 1;

    int profit = 0;
    int maxProfit = 0;

    while (sell < n)
    {
        if (prices[sell] > prices[buy])
        {
            profit = prices[sell] - prices[buy];
            maxProfit = max(maxProfit, profit);
        }
        else
        {
            buy = sell;
        }
        sell++;
    }
    return maxProfit;
}

int main()
{
    /*
    You are given an array prices where prices[i] is the price of a given stock on the ith day.

    You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
    */
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << maxProfit(prices) << endl;
    return 0;
}