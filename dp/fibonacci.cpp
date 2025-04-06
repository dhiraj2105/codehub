#include <bits/stdc++.h>
using namespace std;

int fib(int num)
{
    if (num <= 1)
    {
        return num;
    }

    return fib(num - 1) + fib(num - 2);
}

int main()
{
    int n;
    cout << "Enter number : ";
    cin >> n;

    cout << "The fibonacci of " << n << " is : " << fib(n) << endl;

    return 0;
}