#include <bits/stdc++.h>
using namespace std;

// Function to perform interpolation search
int interpolcationSearch(vector<int> &nums, int target)
{
    // Initialize low and high pointers
    int low = 0;
    int high = nums.size() - 1; // Set high to the last index of the array

    int index; // Variable to store the calculated index
    // Continue searching while the target is within the bounds of the current range
    while (low <= high && target >= nums[low] && target <= nums[high])
    {
        // Prevent division by zero if the values at low and high are the same
        if (nums[high] == nums[low])
        {
            break;
        }

        // Calculate the estimated index using the interpolation formula
        index = low + (high - low) * (target - nums[low]) / (nums[high] - nums[low]);

        cout << "Guessed : " << index << endl;

        // Ensure the calculated index is within the bounds of the array
        if (index < 0 || index >= nums.size())
        {
            break; // Exit if the index is out of bounds
        }

        // Check if the target is found at the calculated index
        if (target == nums[index])
        {
            return index; // Return the index if the target is found
        }
        // If the target is less than the value at the calculated index, adjust the high pointer
        else if (target < nums[index])
        {
            high = index - 1; // Narrow the search to the left half
        }
        // If the target is greater than the value at the calculated index, adjust the low pointer
        else
        {
            low = index + 1; // Narrow the search to the right half
        }
    }
    return -1; // Return -1 if the target is not found
}

int main()
{
    // Array must be sorted for interpolation search to work correctly
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int target; // Variable to store the target value to search for
    cout << "Enter target value : ";
    cin >> target; // Input the target value from the user

    // Call the interpolation search function and store the result
    int res = interpolcationSearch(arr, target);
    // Output the result
    cout << "Index of element is " << res << endl;

    return 0; // End of the program
}