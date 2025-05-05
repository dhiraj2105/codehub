#include <bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        nums[i] = nums[i] + nums[i - 1];
    }

    return nums;
}

int main()
{
    /*
    Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

    Return the running sum of nums.
    */

    vector<int> nums = {1, 2, 3, 4};

    vector<int> res = runningSum(nums);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " , ";
    }

    return 0;
}