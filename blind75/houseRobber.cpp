#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> &nums)
{
    if (nums.size() < 2)
    {
        return nums[0];
    }

    // create arr to store max money at each index
    vector<int> dp(nums.size());

    // memoize max money at first 2 indexes;
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    // use them to fill array
    for (int i = 2; i < nums.size(); i++)
    {
        // core logic
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }

    return dp[nums.size() - 1];
}

int main()
{
    /*
    You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

    Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
    */

    // vector<int> nums = {1, 2, 3, 1};
    vector<int> nums = {2, 7, 9, 3, 1};

    cout << rob(nums) << endl;

    return 0;
}