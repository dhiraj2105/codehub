#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> nums = {9, 4, 7, 5, 2, 1, 3, 6};

    // bubble sort algorithm
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }

    // print the array
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}