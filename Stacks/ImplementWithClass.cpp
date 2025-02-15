#include <bits/stdc++.h>
using namespace std;

template <typename T> // T is the placeholder for data type user will provide

// Define class for stack / structure of stack
class Stack
{
private:
    T *arr;       // Pointer to array that will hold stack elements
    int top;      // Index of the elements
    int capacity; // Maximum size of stack

public:
    // Constructor to init stack with given size
    Stack(int size)
    {
        capacity = size;
        arr = new T[capacity];
        top = -1;
    }

    // Destructure to free dynamic allocated memory
    ~Stack()
    {
        delete[] arr;
    }

    // Push function
    void push(T value)
    {
        if (top == capacity - 1)
        {
            cout << "Stack overflow! Cannot push " << endl;
            return;
        }
        top++;
        arr[top] = value;
        cout << value << " pushed to stack " << endl;
    }

    T pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty! Cannot pop " << endl;
            return T(); // return default value of type T
        }
        return arr[top--]; // return the top element and decrement top
    }

    T peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty! Cannot peek " << endl;
            return T(); // return default value of type T
        }
        return arr[top];
    }
};

int main()
{
    // Stack for integer
    Stack<int> intStack(5);
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    cout << "Top element is " << intStack.peek() << endl;
    cout << "Popped element is " << intStack.pop() << endl;

    // Stack for string
    Stack<string> strStack(3);
    strStack.push("Hello");
    strStack.push("World");
    cout << "Top element is " << strStack.peek() << endl;
    cout << "Popped element is " << strStack.pop() << endl;

    return 0;
}