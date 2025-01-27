#include <bits/stdc++.h>
using namespace std;

// Function to print sequence: 1, 2, 3, 4, ..., n
void one(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
}

// Function to print sequence: 1, 1, 2, 2, 3, 3, ..., n
void two(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << ", " << i << ", ";
    }
    cout << endl;
}

// Function to print sequence: 1, 2, 3, 2, 1, 2, 3, 2, 1
void three(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cout << j << " ";
        }
        for (int j = 3; j >= 1; j--)
        {
            cout << j << " ";
        }
    }
    cout << endl;
}

// Function to print squares of numbers: 1, 4, 9, 16, ..., n
void four(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i * i << " ";
    }
    cout << endl;
}

// Function to print cubes of numbers: 1, 8, 27, 64, ..., n
void five(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i * i * i << " ";
    }
    cout << endl;
}

// Function to print: 0, 3, 8, 15, 24, ..., n
void six(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i * i + 2 << " ";
    }
    cout << endl;
}

// Function to print: 1, 2, 4, 7, 11, 16, ..., n
void seven(int n)
{
    int current = 1; // Start with the first number
    for (int i = 1; i <= n; i++)
    {
        cout << current << " ";
        current += i; // Increment by the current index
    }
    cout << endl;
}

int main()
{
    /*
    Logic building with numbers
    */
    int n = 10;

    // 1,2,3,4,5,6,7,....n
    one(n);

    // 1,1,2,2,3,3,4,4....n
    two(n);

    // 1,2,3,2,1,2,3....n
    three(n);

    // 1,4,9,16....n
    four(n);

    // 1,8,27,64....n
    five(n);

    // 0,3,8,15....n
    six(n);

    // 1,2,4,7,11....n
    seven(n);

    return 0;
}
