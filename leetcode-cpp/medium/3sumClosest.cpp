#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
    // Step 1: Sort the array to make it easier to find the closest sum
    sort(nums.begin(), nums.end());

    // Step 2: Initialize closestSum with a large value (INT_MAX) to store the closest sum found so far
    long long closestSum = INT_MAX;

    // Step 3: Iterate through the array to fix the first number in the triplet
    for (int i = 0; i < nums.size(); i++)
    {
        // Step 4: Initialize two pointers, left and right, to find the other two numbers in the triplet
        int left = i + 1;
        int right = nums.size() - 1;

        // Step 5: Use a while loop to find the closest sum using the two-pointer technique
        while (left < right)
        {
            // Step 6: Calculate the sum of the current triplet
            int sum = nums[i] + nums[left] + nums[right];

            // Step 7: Check if the current sum is closer to the target than the previously found closest sum
            cout << "->" << "i :" << i << " " << "value of i: " << nums[i] << endl;
            cout << "   Sum : " << sum << endl;
            cout << "   Target - Sum : " << abs(target - sum) << endl;
            cout << "   Closest Sum : " << closestSum << endl;
            cout << "   Target - Closest : " << abs(target - closestSum) << endl;

            if (abs(target - sum) < abs(target - closestSum))
            {
                // Step 8: If yes, update the closestSum with the current sum
                closestSum = sum;
            }

            // Step 9: Adjust the pointers based on whether the current sum is less than or greater than the target
            if (sum < target)
            {
                left++; // Move the left pointer to the right to increase the sum
            }
            else
            {
                right--; // Move the right pointer to the left to decrease the sum
            }
        }
    }

    // Step 10: Return the closest sum found
    return closestSum;
}

int main()
{
    /*
    Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

    Return the sum of the three integers.

    You may assume that each input would have exactly one solution.
    */
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    cout << threeSumClosest(nums, target) << endl;
    return 0;
}