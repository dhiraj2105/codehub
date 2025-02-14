#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int n = nums.size();

    int factN = 0;
    for (int i = 1; i <= n; i++)
    {
        factN = factN + i;
    }

    int factNums = 0;
    for (int i = 0; i < n; i++)
    {
        factNums = factNums + nums[i];
    }
    // return missing number
    return (factN - factNums);
}
int main()
{
    /*
    Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
    */
    vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << missingNumber(nums) << endl;
    return 0;
}