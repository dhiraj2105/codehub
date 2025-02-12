#include <bits/stdc++.h>
using namespace std;

vector<int> countingBits(int n)
{
    // Brute force
    // vector<int> ans(n + 1, 0);
    // for (int i = 0; i <= n; i++)
    // {
    //     int num = i;
    //     int count = 0;
    //     while (num)
    //     {
    //         count += num % 2;
    //         num /= 2;
    //     }
    //     ans[i] = count;
    // }
    // return ans;

    // Better method
    vector<int> ans(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            ans[i] = ans[i / 2];
        }
        else
        {
            ans[i] = ans[i / 2] + 1;
        }
    }
    return ans;
}

int main()
{
    /*
    Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
    */
    int n = 5;
    vector<int> ans = countingBits(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}