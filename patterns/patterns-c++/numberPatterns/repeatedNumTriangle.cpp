#include <bits/stdc++.h>
using namespace std;
int main()
{

    // Example
    // 1
    // 2 2
    // 3 3 3
    // 4 4 4 4

    int n = 5;

    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= row; col++)
        {
            cout << row << " ";
        }
        cout << endl;
    }

    return 0;
}