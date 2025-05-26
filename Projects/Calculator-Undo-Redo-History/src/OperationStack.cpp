#include "OperationStack.h"
#include <stdexcept>

// Push an operation onto stack
void OperationStack::push(const Operation &op)
{
    stack.push_back(op);
}

// Remove and return the top operation
Operation OperationStack::pop()
{
    if (isEmpty())
    {
        throw std::out_of_range("Stack is empty"); // Safety check
    }

    Operation top = stack.back(); // Get last element
    stack.pop_back();             // Remove last element
    return top;                   // Return removed operation
}

// Return the top operation without removing it
Operation OperationStack::peek() const
{
    if (isEmpty())
    {
        throw std::out_of_range("Stack is empty"); // Safety check
    }

    return stack.back(); // Return last element
}

// Return true if the stack is empty
bool OperationStack::isEmpty() const
{
    return stack.empty(); // Check if vector is empty
}

// Clear all elements from the stack
void OperationStack::clear()
{
    stack.clear(); // Erase all elements
}

// Return the current size of the stack
int OperationStack::size() const
{
    return stack.size(); // Return vector size
}