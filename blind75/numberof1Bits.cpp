#include <bits/stdc++.h>
using namespace std;
int hammingWeight(int n)
{
    int res = 0;
    while (n)
    {
        res += n % 2;
        n = n >> 1;
    }
    return res;
}
int main()
{

    /*
    Given a positive integer n, write a function that returns the number of
set bits
 in its binary representation (also known as the Hamming weight).
    */
    int n = 2147483645;

    cout << hammingWeight(n) << endl;
    return 0;
}