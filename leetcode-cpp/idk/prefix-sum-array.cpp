#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Given an array arr[] of size N, find the prefix sum of the array, A profix sum array is another array prefixSum[] of the same size, such that the value of prefix sum[i] is arr[0] + arr[1] ,,, arr[i].
    vector<int> arr = {10, 20, 10, 5, 15};

    // initialise prefixSumArray
    vector<int> prefixSumArray(arr.size(), 0);
    // setting first index of prefix array to same of arr
    prefixSumArray[0] = arr[0];

    // finding prefisum
    for (int i = 1; i < arr.size(); i++)
    {
        prefixSumArray[i] = prefixSumArray[i - 1] + arr[i];
    }

    // print array
    for (int i = 0; i < prefixSumArray.size(); i++)
    {
        cout << prefixSumArray[i] << " ";
    }

    return 0;
}