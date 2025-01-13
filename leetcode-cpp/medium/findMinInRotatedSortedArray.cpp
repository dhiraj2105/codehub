#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
    // Initialize the low and high pointers to the start and end of the array
    int low = 0, high = nums.size() - 1;

    // Continue the search until the low and high pointers meet
    while (low < high)
    {
        // Calculate the middle index
        int mid = low + (high - low) / 2;

        // If the middle element is greater than the last element, the minimum element must be in the right half
        if (nums[mid] > nums[high])
        {
            // Move the low pointer to the right half
            low = mid + 1;
        }
        else
        {
            // Otherwise, the minimum element must be in the left half
            // Move the high pointer to the left half
            high = mid;
        }
    }

    // At this point, the low and high pointers have met, and the minimum element is at the low index
    return nums[low];
}

int main()
{
    /*
    Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

    [4,5,6,7,0,1,2] if it was rotated 4 times.
    [0,1,2,4,5,6,7] if it was rotated 7 times.
    Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

    Given the sorted rotated array nums of unique elements, return the minimum element of this array.

    You must write an algorithm that runs in O(log n) time.
    */
    vector<int> nums = {3, 4, 5, 1, 2};

    cout << findMin(nums) << endl;
    return 0;
}