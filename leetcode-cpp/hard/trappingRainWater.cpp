#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
    // Handle edge case where there are less than 3 bars
    if (height.size() < 3)
        return 0;

    // Declare two vectors to store the maximum height from the left and right
    vector<int> left_max(height.size()), right_max(height.size());

    // Initialize the first element of the 'left_max' vector to be the height of the first bar
    left_max[0] = height[0];

    // Loop through the rest of the 'height' array starting from index 1
    for (int i = 1; i < height.size(); i++)
    {
        // For each bar, calculate the maximum height encountered so far from the left
        left_max[i] = max(left_max[i - 1], height[i]);
    }

    // Set the last element of the 'right_max' vector to be the height of the last bar
    right_max[height.size() - 1] = height[height.size() - 1];

    // Loop through the 'height' array from right to left, starting from the second last element
    for (int i = height.size() - 2; i >= 0; i--)
    {
        // For each bar, calculate the maximum height encountered so far from the right
        right_max[i] = max(right_max[i + 1], height[i]);
    }

    // Initialize a variable 'ans' to accumulate the total amount of water trapped
    int ans = 0;

    // Loop through all the bars in the height array
    for (int i = 0; i < height.size(); i++)
    {
        // Calculate the trapped water at each position:
        // The trapped water is determined by the minimum of the maximum heights from the left and right minus the current height
        ans += max(0, min(left_max[i], right_max[i]) - height[i]);
    }

    // Return the total trapped water
    return ans;
}

int main()
{
    /*
    Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
    */
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result = trap(height);
    cout << "Result: " << result << endl; // Expected output is 6
    return 0;
}
