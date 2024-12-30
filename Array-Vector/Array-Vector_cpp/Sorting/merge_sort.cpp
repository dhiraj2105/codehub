#include <bits/stdc++.h>
using namespace std;

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

void mergeSort(vector<int> &nums)
{
    if (nums.size() <= 1)
    {
        return;
    }
    int mid = nums.size() / 2;
    vector<int> leftArr(nums.begin(), nums.begin() + mid);
    vector<int> rightArr(nums.begin() + mid, nums.end());

    mergeSort(leftArr);
    mergeSort(rightArr);
    merger(nums, leftArr, rightArr);
}

int main()
{
    vector<int> nums = {1, 3, 2, 7, 4, 9, 3, 7, 0};
    mergeSort(nums);

    // Print sorted array
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}