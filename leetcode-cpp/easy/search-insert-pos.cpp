#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= target)
        {
            return i;
        }
        }
    return nums.size();
}

int main()
{
    /* Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

   You must write an algorithm with O(log n) runtime complexity. */

    vector<int> nums = {1, 3, 5, 6};
    int target = 7;

    int result = searchInsert(nums, target);
    cout << result << endl;
    return 0;
}