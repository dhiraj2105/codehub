#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
Approach:
1. **Prefix Sum Concept**:
   - A "prefix sum" is the cumulative sum of elements up to the current index.
   - For example, if the array is [1, 2, 3], the prefix sums are:
     - prefix sum at index 0: 1
     - prefix sum at index 1: 1 + 2 = 3
     - prefix sum at index 2: 1 + 2 + 3 = 6

2. **Using a Hash Map**:
   - We maintain a hash map (`mpp`) to store the frequency of each prefix sum as we traverse the array.
   - For every element in the array, calculate the current prefix sum and check if the difference between the current prefix sum and the target sum `k` (i.e., `prefixSum - k`) exists in the map.
   - If it exists, it means that there are one or more subarrays with a sum of `k` that end at the current index.

3. **Steps in the Function**:
   - Traverse the array, and for each element, calculate the prefix sum.
   - If the difference between the prefix sum and `k` exists in the map, add its frequency to the count of subarrays.
   - After checking, update the map with the current prefix sum.

4. **Result**:
   - The count of valid subarrays is returned as the result.
*/

int subarraySum(vector<int> &nums, int k)
{
    // Step 1: Initialize a hashmap to store the frequency of each prefix sum
    unordered_map<int, int> mpp;

    // Step 2: Initialize the map with a prefix sum of 0 having frequency 1
    mpp[0] = 1;

    // Step 3: Initialize variables to track the current prefix sum and the result count
    int prefixSum = 0, count = 0;

    // Step 4: Traverse through the array to calculate the prefix sum at each index
    for (int i = 0; i < nums.size(); i++)
    {
        // Update the prefix sum by adding the current element
        prefixSum += nums[i];

        // Step 5: Check if there exists a previous prefix sum such that (prefixSum - k) has occurred
        // If it exists, it means we've found a subarray with sum = k
        if (mpp.find(prefixSum - k) != mpp.end())
        {
            // Add the frequency of prefixSum - k to the result count
            count += mpp[prefixSum - k];
        }

        // Step 6: Update the hashmap with the current prefix sum
        mpp[prefixSum]++;
    }

    // Step 7: Return the total count of subarrays with sum = k
    return count;
}

int main()
{
    // Example input array
    vector<int> nums = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int k = 3;

    // Call the subarraySum function and output the result
    cout << "Total subarrays with sum " << k << ": " << subarraySum(nums, k) << endl;

    return 0;
}
