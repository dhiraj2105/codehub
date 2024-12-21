#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n = 5;
    // Example
    //     *
    //    ***
    //   *****
    //  *******

    for (int row = 1; row <= n; row++)
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

    return 0;
}