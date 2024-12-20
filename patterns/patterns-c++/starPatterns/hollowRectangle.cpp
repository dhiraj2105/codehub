#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    // Example
    // * * * * *
    // *       *
    // *       *
    // *       *
    // * * * * *

    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n; col++)
        {
            if (row == 1 || row == n || col == 1 || col == n)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}