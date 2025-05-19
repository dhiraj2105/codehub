#include <bits/stdc++.h>
using namespace std;

string triangleType(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int a = nums[0], b = nums[1], c = nums[2];

    if (a + b <= c)
    {
        return "none";
    }

    // Check for triangle types
    if (a == b && b == c)
    {
        return "equilateral";
    }
    else if (a == b || a == c || b == c)
    {
        return "isosceles";
    }
    else
    {
        return "scalene";
    }
}

int main()
{
    /*
    You are given a 0-indexed integer array nums of size 3 which can form the sides of a triangle.

    A triangle is called equilateral if it has all sides of equal length.
    A triangle is called isosceles if it has exactly two sides of equal length.
    A triangle is called scalene if all its sides are of different lengths.
    Return a string representing the type of triangle that can be formed or "none" if it cannot form a triangle.
    */

    vector<int> nums = {3, 3, 5};

    cout << triangleType(nums);

    return 0;
}