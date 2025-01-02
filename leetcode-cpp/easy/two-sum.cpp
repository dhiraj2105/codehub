#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> nums, int target)
{
    // brute force method
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     for (int j = i + 1; j < nums.size(); j++)
    //     {
    //         if (nums[i] + nums[j] == target)
    //         {
    //             return {i, j};
    //         }
    //     }
    // }
    // return {0, 0};

    // BETTER WAY - HASHMAP

    unordered_map<int, int> num_dict; // empty map

    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];
        // check if complement exsists in map
        if (num_dict.find(complement) != num_dict.end())
        {
            // return the indeces of current number and the complement
            return {num_dict[complement], i};
        }
        num_dict[nums[i]] = i; // store current number and its index
    }
    return {};
}

int main()
{
    /*
    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    You can return the answer in any order.
    */
    vector<int> nums = {3, 2, 4};
    int target = 6;

    twoSum(nums, target);

    // print return from above function
    for (int i = 0; i < twoSum(nums, target).size(); i++)
    {
        cout << twoSum(nums, target)[i] << " ";
    }

    return 0;
}