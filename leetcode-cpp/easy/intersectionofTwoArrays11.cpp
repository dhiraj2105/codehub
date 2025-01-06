#include <bits/stdc++.h>
using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    // brute force
    // vector<int> res;
    // for (int i : nums1)
    // {
    //     auto j = find(nums2.begin(), nums2.end(), i);
    //     if (j != nums2.end())
    //     {
    //         res.push_back(i);
    //         nums2.erase(j);
    //     }
    // }

    // hashmap
    vector<int> res;
    unordered_map<int, int> m;
    for (int i : nums1)
    {
        m[i]++;
    }
    for (int i : nums2)
    {
        if (m[i] > 0)
        {
            res.push_back(i);
            m[i]--;
        }
    }

    return res;
}

int main()
{
    /*
    Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
    */
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};

    vector<int> result = intersect(nums1, nums2);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}