#include <bits/stdc++.h>
using namespace std;

bool validMountainArray(vector<int> &arr)
{
    int n = arr.size();
    if (n < 3)
    {
        return false;
    }
    int i = 0;

    // find the peak
    while (i + 1 < n && arr[i] < arr[i + 1])
    {
        i++;
    }

    // Check if the peak is not at the start or end of the array
    if (i == 0 || i == n - 1)
    {
        return false; // No valid peak found
    }

    // Traverse the array to ensure the strictly decreasing part after the peak
    while (i + 1 < n && arr[i] > arr[i + 1])
    {
        i++;
    }

    // If we reach the end of the array, it's a valid mountain array
    return i == n - 1;
}

int main()
{
    /*
    Given an array of integers arr, return true if it is a valid mountain array.
    */
    vector<int> arr = {0, 3, 2, 1};
    return 0;
}