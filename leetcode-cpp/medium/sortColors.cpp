#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &nums)
{
    if (nums.size() <= 1)
    {
        return;
    }
    int mid = nums.size() / 2;
    vector<int> leftArr(nums.begin(), nums.begin() + mid);
    vector<int> rightArr(nums.begin() + mid, nums.end());

    sortColors(leftArr);
    sortColors(rightArr);
    merger(nums, leftArr, rightArr);
}

void merger(vector<int> &nums, const vector<int> &leftArr, const vector<int> &rightArr)
{
    int i = 0, l = 0, r = 0;

    while (l < leftArr.size() && r < rightArr.size())
    {
        if (leftArr[l] < rightArr[r])
        {
            nums[i++] = leftArr[l++];
        }
        else
        {
            nums[i++] = rightArr[r++];
        }
    }
    while (l < leftArr.size())
    {
        nums[i++] = leftArr[l++];
    }
    while (r < rightArr.size())
    {
        nums[i++] = rightArr[r++];
    }
}

int main()
{

    /*
    Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

    We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

    You must solve this problem without using the library's sort function.
    */
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sortColors(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}