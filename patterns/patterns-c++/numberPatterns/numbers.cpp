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

void eight(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // if i == 5,7,9,11,17,19,21,23 continue
        if (i == 5 || i == 7 || i == 9 || i == 11 || i == 17 || i == 19 || i == 21 || i == 23)
        {
            continue;
        }
        cout << i;
    }
    cout << endl;
}

// Function to print Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55...
void nine(int n)
{
    int a = 0, b = 1;
    cout << a << " ";
    if (n > 1)
        cout << b << " ";
    for (int i = 3; i <= n; i++)
    {
        int c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
    cout << endl;
}

// Function to print: 0, 1, 2, 3, 6, 11, 20, 37, 57...
void ten(int n)
{
    int a = 0, b = 1, c;
    for (int i = 0; i < n; i++)
    {
        cout << c << " ";
        int c = a + b;
        a = b;
        b = c;
        if (i % 2 == 0)
        {
            a = b;
            b = c;
        }
    }
    cout << endl;
}

// Function to print: 5, 7, 11, 16, 22, 30, 40, 52...
void eleven(int n)
{
    int current = 5, increment = 2;
    for (int i = 1; i <= n; i++)
    {
        cout << current << " ";
        current += increment;
        if (i % 2 == 0)
        {
            increment++;
        }
        else
        {
            increment += 2;
        }
    }
    cout << endl;
}

// Function to print: 2, 6, 12, 20, 30, 42...
void twelve(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i * (i + 1) << " "; // Formula: i * (i + 1)
    }
    cout << endl;
}

// Function to print: 1, 2, 2, 4, 3, 6, 4, 8, 5, 10...
void thirteen(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            cout << i << " "; // Even index: print the number itself
        else
            cout << (i + 1) / 2 << " "; // Odd index: print (index + 1) / 2
    }
    cout << endl;
}

// Function to print: 5, 15, 24, 32, 38, 42...
void fourteen(int n)
{
    int current = 5;
    for (int i = 1; i <= n; i++)
    {
        cout << current << " ";
        if (i <= 2)
            current += 10; // First two terms increment by 10
        else if (i <= 4)
            current += 8; // Next two terms increment by 8
        else
            current += 4; // Remaining terms increment by 4
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
    // add more functions after seven
    eight(n);
    nine(n);
    ten(n);
    eleven(n);
    twelve(n);
    thirteen(n);
    fourteen(n);

    return 0;
}
