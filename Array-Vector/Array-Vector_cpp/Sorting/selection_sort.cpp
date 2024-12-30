#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> nums)
{
    int min, temp; // temp is used to swap elements
    for (int i = 0; i < nums.size() - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[min])
            {
                min = j;
            }
        }
        temp = nums[i];
        nums[i] = nums[min];
        nums[min] = temp;
    }

    // print array
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}

int main()
{

    vector<int> nums = {2, 1, 6, 3, 7, 8, 9, 4, 5};

    selectionSort(nums);
    return 0;
}