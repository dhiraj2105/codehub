#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> product;

    for (int i = 0; i < n; i++)
    {
        int left = 1;
        int right = 1;
        for (int j = 0; j < i; j++)
        {
            left = left * nums[j];
        }
        for (int j = i + 1; j < n; j++)
        {
            right = right * nums[j];
        }
        product.push_back(left * right);
    }

    return product;
}

int main()
{

    /*
    Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

    You must write an algorithm that runs in O(n) time and without using the division operation.
    */
    vector<int> nums = {1, 2, 3, 4};

    vector<int> result = productExceptSelf(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}