#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Example
    // * * * * *
    // * * * *
    // * * *
    // * *
    // *

    int n = 5;

    for (int row = 1; row <= n; row++)
    {
        // col <= n - row + 1
        /*
            when row = 1, 5-1+1 = 5
            when row = 2, 5-2+1 = 4
            when row = 3, 5-3+1 = 3
            when row = 4, 5-4+1 = 2
            when row = 5, 5-5+1 = 1
        */
        for (int col = 1; col <= n - row + 1; col++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}