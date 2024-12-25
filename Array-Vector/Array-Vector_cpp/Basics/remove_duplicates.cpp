#include <bits/stdc++.h>
using namespace std;
int main()
{
    //  Remove duplicates
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    sort(nums.begin(), nums.end());

    int i = 1, j = 1;

    while (j < nums.size())
    {
        if (nums[j] != nums[j - 1])
        {
            nums[i] = nums[j];
            i++;
            j++;
        }
        else
        {

            j++;
        }
    }
    cout << i << endl;

    for (int k = 0; k < nums.size(); k++)
    {
        cout << nums[k] << " ";
    }

    return 0;
}