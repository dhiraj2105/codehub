#include <bits/stdc++.h>
using namespace std;

#define SIZE 5   // size of stack
int Stack[SIZE]; // array which is used to implement stack : this is our stack
int top = -1;    // stack/array index

// push operations on stack
void push()
{
    cout << "Enter the data to push: ";
    int data;
    cin >> data;

    // check if stack is not full
    if (top == SIZE - 1)
    {
        cout << "----- Stack is full [Overflow]. Cannot push " << data << endl;
    }
    else
    {
        top++;
        Stack[top] = data;
        cout << data << " pushed to stack" << endl;
    }
}

int pop()
{
    if (top == -1)
    {
        cout << "----- Stack is empty [Underflow]. Cannot pop" << endl;
    }
    else
    {
        cout << Stack[top] << " popped from stack" << endl;
        top--;
    }
    return Stack[top];
}
int peek()
{
    if (top == -1)
    {

        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Top element of stack is: " << Stack[top] << endl;
    }
    return Stack[top];
}

void display()
{
    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--)
    {
        cout << Stack[i] << " ";
    }
    cout << endl;
}

int main()
{
    while (1)
    {
        cout << "-> Whay you want to do ?" << endl;
        cout << " 1. Push \n 2. Pop \n 3. Top \n 4. Display" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            cout << "Popped element is: " << pop() << endl;
            break;
        case 3:
            cout << "Top element is: " << peek() << endl;
            break;
        case 4:
            display();
            break;
        default:
            cout << "   Operations on stack are : " << endl;
            cout << "   1. Push : Add an element to the top of stack" << endl
                 << "   2. Pop : Remove[Delete] an element from the top of stack" << endl
                 << "   3. Top : Returns the top element from the stack" << endl
                 << "   4. Display : Display all elements in the stack" << endl;
        }
    }
    return 0;
}