#include <bits/stdc++.h>
using namespace std;

int main()
{

    stack<int> myStack;

    myStack.push(21);
    myStack.push(11);
    myStack.push(31);
    myStack.push(45);

    while (!myStack.empty())
    {
        cout << myStack.top() << endl;
        myStack.pop();
    }

    cout << "new" << endl;
    myStack.push(21);
    myStack.push(11);
    myStack.push(31);
    myStack.push(45);

    myStack.pop();

    while (!myStack.empty())
    {
        cout << myStack.top() << endl;
        myStack.pop();
    }
    return 0;
}