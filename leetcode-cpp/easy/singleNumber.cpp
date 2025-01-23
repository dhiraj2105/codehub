#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
    // init result with 0
    int result = 0;

    // iterate each element
    for (int num : nums)
    {
        // XOR result with element in array
        // IF THE BITS ARE SAME THEN = 0
        // IF THE BITS ARE num and 0 THEN = num
        result = result ^ num;
    }
    return result;
}

int main()
{
    /*
    Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

    You must implement a solution with a linear runtime complexity and use only constant extra space.
    */
    vector<int> nums = {1, 2, 3, 2, 1};

    cout << singleNumber(nums) << endl;
    return 0;
}