#include <bits/stdc++.h>
#include "utility.h"

using namespace std;

class Stack
{

private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size)
    {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int value)
    {
        if (top == capacity - 1)
        {
            Utility::printWarning("Stack Overflow! Cannot push more elements");
            return;
        }
        arr[++top] = value;
        Utility::printSuccess("Value pushed to stack");
    }

    void pop()
    {
        if (top < 0)
        {
            Utility::printWarning("Stack underflow");
            return;
        }
        Utility::printSuccess("Popping done");
        top--;
    }

    void display()
    {
        if (top < 0)
        {
            Utility::printWarning("Stack is empty");

            return;
        }

        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " | ";
        }
    }
};

void stackMenu()
{
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;
    Stack stackObj(size);

    int choice, value;
    do
    {
        Utility::printInfo("Stack Operations Menu");
        cout
            << "1. Push\n2. Pop\n3. Display\n4. Back to Main Menu\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            stackObj.push(value);
            break;
        case 2:
            stackObj.pop();
            break;
        case 3:
            stackObj.display();
            break;
        case 4:
            Utility::printInfo("Returning to main menu");

            break;
        default:
            Utility::printError("Invalid choice");
        }
    } while (choice != 4);
}