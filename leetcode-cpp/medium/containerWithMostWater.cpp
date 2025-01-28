#include <bits/stdc++.h>
using namespace std;
int maxArea(vector<int> &height)
{
    int left = 0, right = height.size() - 1, maxArea = 0; // Initialize the pointers and maxArea
    while (left < right)
    {
        int area = min(height[left], height[right]) * (right - left);
        maxArea = max(area, maxArea);
        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return maxArea;
}

int main()
{
    /*
    You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

    Find two lines that together with the x-axis form a container, such that the container contains the most water.

    Return the maximum amount of water a container can store.

    Notice that you may not slant the container.
    */
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << maxArea(height) << endl;

    return 0;
}