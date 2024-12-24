#include <bits/stdc++.h>
using namespace std;
int main()

{
    // Time Complexity : O(n^2)
    vector<int> arr = {1, 2, 1, 3, 4, 5};

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}