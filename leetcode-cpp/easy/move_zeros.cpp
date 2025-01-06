#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int nonZeroIndxe = 0;

    // filling non zero elements to front
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            nums[nonZeroIndxe] = nums[i];
            nonZeroIndxe++;
        }
    }

    // fill remaining pos with zeros
    for (int i = nonZeroIndxe; i < nums.size(); i++)
    {
        nums[i] = 0;
    }
}

int main()
{

    /*
    Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

    Note that you must do this in-place without making a copy of the array.
    */
    vector<int> nums = {0, 1, 0, 3, 12};

    moveZeroes(nums);

    return 0;
}