#include <bits/stdc++.h>
using namespace std;
int main()
{

    // Example
    // 1
    // * *
    // 1 2 3
    // * * * *

    int n = 5;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i % 2 == 0)
            {
                cout << "* ";
            }
            else
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }

    return 0;
}