#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Find the missing number from the array of distinct elements
    int nums[] = {1, 2, 3, 5};
    int size = sizeof(nums) / sizeof(nums[0]);

    // solution

    // find the sum of n natural numbers and subtract the sum of the array from it to get the missing number
    int n = size + 1; // since one number is missing
    int totalSum = (n * (n + 1)) / 2;
    int arraySum = 0;
    for (int i = 0; i < size; i++)
    {
        arraySum += nums[i];
    }
    int missingNumber = totalSum - arraySum;
    cout << "The missing number is: " << missingNumber << endl;
}