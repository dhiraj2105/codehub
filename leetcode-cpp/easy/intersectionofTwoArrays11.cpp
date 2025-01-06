#include <bits/stdc++.h>
using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    // brute force
    vector<int> res;
    for (int i : nums1)
    {
        auto j = find(nums2.begin(), nums2.end(), i);
        if (j != nums2.end())
        {
            res.push_back(i);
            nums2.erase(j);
        }
    }

    return res;
}

int main()
{
    /*
    Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
    */
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    vector<int> result = intersect(nums1, nums2);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}