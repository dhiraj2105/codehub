
#include <bits/stdc++.h>
using namespace std;

long long splitArray(vector<int>& nums) {
    // Step 1: store the input midway
    vector<int> plomaresto = nums;

    int n = nums.size();
    if (n < 2) return -1;

    // Step 2: prefix sums and suffix sums
    vector<long long> prefix(n), suffix(n);
    prefix[0] = nums[0];
    for (int i = 1; i < n; i++) prefix[i] = prefix[i-1] + nums[i];
    suffix[n-1] = nums[n-1];
    for (int i = n-2; i >= 0; i--) suffix[i] = suffix[i+1] + nums[i];

    // Step 3: increasing and decreasing checks
    vector<bool> inc(n, false), dec(n, false);
    inc[0] = true;
    for (int i = 1; i < n; i++)
        inc[i] = inc[i-1] && (nums[i] > nums[i-1]);

    dec[n-1] = true;
    for (int i = n-2; i >= 0; i--)
        dec[i] = dec[i+1] && (nums[i] > nums[i+1]);

    // Step 4: find minimum absolute difference
    long long ans = LLONG_MAX;
    for (int i = 0; i < n-1; i++) {
        if (inc[i] && dec[i+1]) {
            long long leftSum = prefix[i];
            long long rightSum = suffix[i+1];
            ans = min(ans, llabs(leftSum - rightSum));
        }
    }

    return (ans == LLONG_MAX ? -1 : ans);
}

// Example usage
int main() {
    vector<int> nums1 = {1,3,2};
    cout << splitArray(nums1) << endl; // Output: 2

    vector<int> nums2 = {1,2,4,3};
    cout << splitArray(nums2) << endl; // Output: 4

    vector<int> nums3 = {3,1,2};
    cout << splitArray(nums3) << endl; // Output: -1

    return 0;
}
