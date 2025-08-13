#include <bits/stdc++.h>
using namespace std;

void bubbleSortWithStats(vector<int> nums)
{
    int totalComparisons = 0;
    int totalSwaps = 0;
    int n = nums.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            totalComparisons++;
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;

                totalSwaps++;
            }
        }
    }

    // Print sorted array
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
    cout << endl;

    // Print stats
    cout << "Total comparisons : " << totalComparisons << endl;
    cout << "Total swaps : " << totalSwaps << endl;
}

int main()
{
    vector<int> nums = {5, 1, 4, 2, 8};
    bubbleSortWithStats(nums);
    return 0;
}
