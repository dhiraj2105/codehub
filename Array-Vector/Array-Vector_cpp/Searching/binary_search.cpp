#include <bits/stdc++.h>
using namespace std;
int main()
{

    // in binary search we divide a sorted array into two parts
    /*
        low =0
        high= array.size()-1
        mid = low(high-low)/2       it shows the middle point between low and high
        everytime we will update these variables util target != mid
    */

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target;
    cout << "Enter the target number : ";
    cin >> target;

    sort(nums.begin(), nums.end()); // It is imprtant to have sorted array for binary search

    int low = 0, high = nums.size() - 1;

    int found = false;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (target == nums[mid])
        {
            cout << "Target found at index " << mid << endl;
            found = true;
            break;
        }
        else if (target > nums[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (!found)
    {
        cout << "Target not found " << endl;
    }

    return 0;
}