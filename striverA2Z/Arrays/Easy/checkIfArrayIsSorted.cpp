#include <bits/stdc++.h>
using namespace std;

int bruteForce(int nums[], int n)
{
    // pick each element and compare with next element to check if next element is greater or not
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    // Check if the array is sorted or not, if yes then return True else False.
    int nums[] = {1, 2, 3, 4, 5};
    int size = sizeof(nums) / sizeof(nums[0]);

    if (bruteForce(nums, size) == 1)
    {
        cout << "Sorted" << endl;
    }
    else
    {
        cout << "Not Sorted" << endl;
    }

    return 0;
}