#include <bits/stdc++.h>
using namespace std;
int main()
{

    // Example
    //   *
    //  * *
    // * * *
    //  * *
    //   *

    int n = 5;

    for (int row = 1; row <= n - 1; row++)
    {
        for (int space = 1; space <= n - row + 1; space++)
        {
            cout << " ";
        }
        for (int col = 1; col <= row; col++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    for (int row = 1; row <= n; row++)
    {
        for (int space = 1; space <= row; space++)
        {
            cout << " ";
        }
        for (int col = 1; col <= n - row + 1; col++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}