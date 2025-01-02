#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{

    // what are we doing => i + 2 sum

    if (nums.size() < 3)
    {
        return {};
    }
    // sort array
    sort(nums.begin(), nums.end());

    // use a sot to store unique triplets
    set<vector<int>> result;

    for (int i = 0; i < nums.size() - 2; i++)
    {
        // performing 2 sum
        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0)
            {
                // add triplet to the set
                result.insert({nums[i], nums[left], nums[right]});
                left++;
                right--;
            }
            else if (sum < 0)
            {
                // if sum is less than 0, more left pointer to increase the sum
                left++;
            }
            else
            {
                // if sum is greater than 0, more right pointer to decrease the sum
                right--;
            }
        }
    }

    // convert the set of triplets to a vector of vectors
    vector<vector<int>> resultVector(result.begin(), result.end());
    return resultVector;
}

int main()
{
    /*
    Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

    Notice that the solution set must not contain duplicate triplets.
    */
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    // vector<int> nums = {0, 0, 0};

    vector<vector<int>> triplets = threeSum(nums);

    // Print the result
    cout << "All unique triplets that sum to zero:" << endl;
    for (auto triplet : triplets)
    {
        cout << "(" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << ")" << endl;
    }

    return 0;
}