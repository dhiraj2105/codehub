#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Also known as    Half pyramid
    // Example
    // *
    // * *
    // * * *
    // * * * *

    int n = 5;

    // here, row will run n times and col will run row times
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= row; col++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}