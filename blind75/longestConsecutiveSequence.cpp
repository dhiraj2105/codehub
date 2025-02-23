#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    int longestLength = 0;
    unordered_map<int, bool> numberTravelledMap;

    // Mark each number as unvisited (false)
    for (int num : nums)
    {
        numberTravelledMap[num] = false;
    }

    // Iterate over the numbers
    for (int num : nums)
    {
        int currentLength = 1;

        // Check in forward direction
        int nextNum = num + 1;
        while (numberTravelledMap.find(nextNum) != numberTravelledMap.end() && !numberTravelledMap[nextNum])
        {
            currentLength++;
            numberTravelledMap[nextNum] = true;
            nextNum++;
        }

        // Check in reverse direction
        int prevNum = num - 1;
        while (numberTravelledMap.find(prevNum) != numberTravelledMap.end() && !numberTravelledMap[prevNum])
        {
            currentLength++;
            numberTravelledMap[prevNum] = true;
            prevNum--;
        }

        longestLength = max(longestLength, currentLength);
    }

    return longestLength;
}

int main()
{
    /*
    Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

    You must write an algorithm that runs in O(n) time.
    */
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    cout << longestConsecutive(nums) << endl;
    return 0;
}