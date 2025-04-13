#include <bits/stdc++.h>
using namespace std;

// Recursive function to find all combinations
void get_sol(vector<int> &candidates, int curr, int target,
             int curr_sum, vector<int> temp, vector<vector<int>> &ans)
{
    // If the current sum equals the target, we've found a valid combination
    if (curr_sum == target)
    {
        ans.push_back(temp); // Add the current combination to the answer list
        return;
    }

    // If the current sum exceeds the target, no point in continuing this path
    if (curr_sum > target)
    {
        return;
    }

    // If we have considered all elements in candidates, return
    if (curr == candidates.size())
    {
        return;
    }

    // Create a new vector to include the current element
    vector<int> a = temp;
    a.push_back(candidates[curr]);

    // Recursive call **including** the current element
    // We do not increment `curr` because we can reuse the same element
    get_sol(candidates, curr, target, curr_sum + candidates[curr], a, ans);

    // Recursive call **excluding** the current element
    // Move to the next index
    get_sol(candidates, curr + 1, target, curr_sum, temp, ans);
}

// This function acts as a wrapper to initialize variables and start the recursion
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans; // To store all the valid combinations
    vector<int> temp;        // To store the current combination while exploring

    // Start recursive exploration
    get_sol(candidates, 0, target, 0, temp, ans);

    return ans;
}

int main()
{
    /*
    Problem:
    Given a list of distinct integers (`candidates`) and a target integer,
    find all unique combinations of candidates where the chosen numbers sum to the target.
    Each number in candidates may be used an unlimited number of times.
    */
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = combinationSum(candidates, target);
    for (auto &combination : result)
    {
        for (auto &num : combination)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}