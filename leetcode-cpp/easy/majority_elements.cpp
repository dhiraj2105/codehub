#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> nums)
{
    // Create a map to store the frequency of each element
    unordered_map<int, int> numMap;

    // Iterate through the vector to count the frequency of each element
    for (int i : nums)
    {
        numMap[i]++; // Increment the count for the current element
    }

    // Iterate through the map to find the element with frequency > n/2
    for (auto &pair : numMap)
    {
        // map is key value pair
        // first is key and second is value [frequency]
        if (pair.second > nums.size() / 2)
        {
            return pair.first; // Return the majority element
        }
    }
    return -1; // Return -1 if no majority element is found (though the problem states it always exists)
}

int main()
{
    /*
    Given an array nums of size n, return the majority element.

    The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
    */
    vector<int> nums = {3, 2, 3, 3, 3, 2};

    // Call the majorityElement function and print the result
    cout << majorityElement(nums) << endl;
    return 0;
}