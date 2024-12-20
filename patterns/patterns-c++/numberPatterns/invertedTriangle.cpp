#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Inveted Half pyramid
    // 1 2 3 4
    // 1 2 3
    // 1 2
    // 1

    int n = 5, k = 1;

    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n - row + 1; col++)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    return 0;
}