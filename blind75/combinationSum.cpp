#include <bits/stdc++.h>
using namespace std;

void get_sol(vector<int> &candidates, int curr, int target,
             int curr_sum, vector<int> temp, vector<vector<int>> &ans)
{
    if (curr_sum == target)
    {
        ans.push_back(temp);
        return;
    }
    if (curr_sum > target)
    {
        return;
    }
    if (curr == candidates.size())
    {
        return;
    }

    vector<int> a = temp;
    a.push_back(candidates[curr]);
    // include
    get_sol(candidates, curr, target, curr_sum + candidates[curr], a, ans);
    // exclude
    get_sol(candidates, curr + 1, target, curr_sum, temp, ans);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;

    get_sol(candidates, 0, target, 0, temp, ans);

    return ans;
}

int main()
{
    /*
    Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

    The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

    The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
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