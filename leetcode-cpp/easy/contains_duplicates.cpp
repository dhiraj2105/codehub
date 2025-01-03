#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int> nums)
{
    bool isDuplicate = false;
    sort(nums.begin(), nums.end());
    int l = 0, r = 1;
    while (r < nums.size())
    {
        if (nums[l] == nums[r])
        {
            isDuplicate = true;
        }
        else
        {
            l++;
        }
        r++;
    }
    return isDuplicate;
}

int main()
{
    /*
    Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
    */
    vector<int> nums = {1, 2, 3, 1};
    cout << boolalpha << containsDuplicate(nums) << endl;
    return 0;
}