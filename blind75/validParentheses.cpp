#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    // this will solve using stack , for now i am using builtin STL stack later i'll solve it by making my own stack from scratch
    stack<char> bracketStack;

    for (char c : s)
    {
        if (c == '(')
        {
            bracketStack.push(')');
        }
        else if (c == '{')
        {
            bracketStack.push('}');
        }
        else if (c == '[')
        {
            bracketStack.push(']');
        }
        else if (bracketStack.empty() || bracketStack.top() != c)
        {
            return false;
        }
        else
        {
            bracketStack.pop();
        }
    }
    return bracketStack.empty();
}
int main()
{
    /*
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
    */
    string s = "()[]{)}";
    if (isValid(s))
    {
        cout << "Valid";
    }
    else
    {
        cout << "Invalid";
    }

    return 0;
}