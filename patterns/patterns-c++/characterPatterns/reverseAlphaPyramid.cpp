#include <bits/stdc++.h>
using namespace std;
int main()
{

    // Example
    // D
    // C C
    // B B B
    // A A A A

    int n = 5;

    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= row; col++)
        {
            cout << char('A' + n - row) << " ";
        }
        cout << endl;
    }
    return 0;
}