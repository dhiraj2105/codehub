#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Half pyramid
    // 1
    // 1 2
    // 1 2 3
    // 1 2 3 4

    int n = 5, k = 1;

    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= row; col++)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    return 0;
}