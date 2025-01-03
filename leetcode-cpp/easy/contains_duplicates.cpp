#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int> nums)
{
    // O(n log n)
    // bool isDuplicate = false;
    // sort(nums.begin(), nums.end());
    // int l = 0, r = 1;
    // while (r < nums.size())
    // {
    //     if (nums[l] == nums[r])
    //     {
    //         isDuplicate = true;
    //     }
    //     else
    //     {
    //         l++;
    //     }
    //     r++;
    // }
    // return isDuplicate;

    // O(n)
    unordered_set<int> seen;
    for (int i = 0; i < nums.size(); i++)
    {
        if (seen.find(nums[i]) != seen.end())
        {
            return true;
        }
        else
        {
            seen.insert(nums[i]);
        }
    }
    return false;

    // O(n)
    // unordered_map<int, int> freq;
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     if (freq.find(nums[i]) != freq.end())
    //     {
    //         freq[nums[i]]++;
    //     }
    //     else
    //     {
    //         freq[nums[i]] = 1;
    //     }
    //     if (freq[nums[i]] > 1)
    //     {
    //         return true;
    //     }
    // }
    // return false;
}

int main()
{
    /*
    Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
    */
    vector<int> nums = {1, 2, 3, 4};
    cout << boolalpha << containsDuplicate(nums) << endl;
    return 0;
}