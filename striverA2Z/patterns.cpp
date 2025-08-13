#include <bits/stdc++.h>
using namespace std;

void one()
{
    // square
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << "X";
        }
        cout << endl;
    }
}

void two()
{
    // triangle
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "X";
        }
        cout << endl;
    }
}

void third()
{
    // number triangle
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void four()
{
    // number triangle
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

void fifth()
{
    // inverted triangle
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 5; j >= i; j--)
        {
            cout << "X ";
        }
        cout << endl;
    }
}

void six()
{
    // number triangle
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5 - i + 1; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void seven()
{
    // pyramid
    int n = 5;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "X";
        }
        cout << endl;
    }
}

int main()
{

    seven();
    return 0;
}