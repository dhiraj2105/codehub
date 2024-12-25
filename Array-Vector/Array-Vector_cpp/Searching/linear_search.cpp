#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums = {1, 3, 5, 2, 7, 4};
    int target = 2;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            cout << "Element " << target << " found at index :" << i << endl;
        }
    }

    return 0;
}