#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Example
    //       *
    //     * *
    //   * * *
    // * * * *

    int n = 5;

    // we have to print space + star
    for (int row = 1; row <= n; row++)
    {
        // space loop
        /* space <= n-row
            row =1 , space = 5-1 =4
            row =2 , space = 5-2 =3
            row =3 , space = 5-3 =2
            row =4 , space = 5-4 =1
            row =5 , space = 5-5 =0
        */
        for (int space = 1; space <= n - row; space++)
        {
            cout << " ";
        }
        // start loop
        for (int col = 1; col <= row; col++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}