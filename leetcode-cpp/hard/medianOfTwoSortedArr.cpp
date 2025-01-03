#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> nums1, vector<int> nums2)
{
    // Ensure nums1 is the smaller array to minimize binary search iterations
    if (nums1.size() > nums2.size())
    {
        return findMedianSortedArrays(nums2, nums1);
    }

    int m = nums1.size(); // size of smaller array [ first ]
    int n = nums2.size(); // size of larger array [ second ]

    // perform binary search on smaller array
    int low = 0, high = m;

    while (low <= high)
    {
        // Partition index for nums1 (divide nums1 into two parts)
        int partition1 = (low + high) / 2;
        // Partition index for nums2
        int partition2 = (m + n + 1) / 2 - partition1;

        // Handle edge cases with partition indexes
        int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
        int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];

        int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
        int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];

        // Check if we have found the correct partitions
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1)
        {
            // If total elements are odd, median is max of left parts
            if ((m + n) % 2 == 1)
            {
                return max(maxLeft1, maxLeft2);
            }
            // If total elements are even, median is average of middle two elements
            return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
        }
        // Adjust the partitions
        else if (maxLeft1 > minRight2)
        {
            high = partition1 - 1; // Move left in nums1
        }
        else
        {
            low = partition1 + 1; // Move right in nums1
        }
    }
    return 0;
}

int main()
{
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2, 4};

    cout << "Median: " << findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}
