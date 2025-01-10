#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // If the target is found at mid, return the index
        if (nums[mid] == target)
        {
            return mid;
        }

        // Check if the left half is sorted
        if (nums[low] <= nums[mid])
        {
            // If the target is within the sorted left half, search in the left half
            if (nums[low] <= target && target < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                // Otherwise, search in the right half
                low = mid + 1;
            }
        }
        else
        {
            // If the right half is sorted, check if the target is within the sorted right half
            if (nums[mid] < target && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                // Otherwise, search in the left half
                high = mid - 1;
            }
        }
    }

    // If the target is not found, return -1
    return -1;
}

int main()
{

    /*
    There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
    */
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int result = search(nums, target);
    std::cout << "The index of the target is: " << result << std::endl;
    return 0;
}