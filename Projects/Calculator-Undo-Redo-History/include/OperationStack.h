#ifndef OPERATION_STACK_H
#define OPERATION_STACK_H

#include "Operations.h"
#include <vector>

// Class to simulate stack for storing operations history , used in undo redo
class OperationStack
{
private:
    std::vector<Operation> stack;

public:
    // push an operation on stack
    void push(const Operation &op);

    // Pop the top operation
    Operation pop();

    // Peek the top
    Operation peek() const;

    bool isEmpty() const;

    void clear();

    int size() const;
};

#endif