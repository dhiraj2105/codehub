#include <bits/stdc++.h>
using namespace std;
int main()
{

    // Example
    // A
    // A B
    // A B C
    // A B C D

    int n = 5;

    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= row; col++)
        {
            cout << char('A' + col - 1) << " ";
        }
        cout << endl;
    }

    return 0;
}