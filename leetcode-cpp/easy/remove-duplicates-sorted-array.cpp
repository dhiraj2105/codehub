#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> nums)
{
    /* we will take two pointers l and r and start from 1st postion , we will check if r is not equal to r-1 */
    int l = 1, r = 1;
    while (r < nums.size())
    {
        if (nums[r] != nums[r - 1])
        {
            nums[l] = nums[r];
            l++;
        }
        r++;
    }

    return l;
}

int main()
{
    /* Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

    Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

    Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
    Return k.
 */
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << removeDuplicates(nums) << endl;
    return 0;
}