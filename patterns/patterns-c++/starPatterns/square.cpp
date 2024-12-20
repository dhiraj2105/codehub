#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;

    // Example
    // * * * *
    // * * * *
    // * * * *
    // * * * *

    // Here row and col will run n times

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}
