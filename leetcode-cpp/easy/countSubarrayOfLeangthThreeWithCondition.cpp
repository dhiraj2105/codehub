#include <bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int> &nums)
{
    if (nums.size() < 3)
    {
        return 0;
    }

    int count = 0;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        int first = nums[i];
        int second = nums[i + 1];
        int third = nums[i + 2];

        if ((first + third) * 2 == second)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    /*
    Given an integer arrays nums, return the number of subarrays of leangth 3 such that the sum of first and third numbers equals exactly half of the second number.
    */

    vector<int> nums = {1, 2, 1, 4, 1};
    // vector<int> nums = {1, 1, 1};
    // vector<int> nums = {-1, -4, -1 ,4};

    cout << countSubarrays(nums);

    return 0;
}