#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;
    // rotate array , example : 5,4,1,2,3

    vector<int> temp(arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        temp[(i + k) % arr.size()] = arr[i];
    }

    // copy temp into arr
    arr = temp;

    // print the array
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}