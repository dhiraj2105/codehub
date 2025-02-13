#include <bits/stdc++.h>
using namespace std;

int getSum(int a, int b)
{
    while (b != 0)
    {
        int tmp = (a & b) << 1;
        a = a ^ b;
        b = tmp;
    }
    return a;
}
int main()
{
    /*
    Given two integers a and b, return the sum of the two integers without using the operators + and -.
    */
    int a = 3;
    int b = 2;
    cout << getSum(a, b) << endl;
    return 0;
}