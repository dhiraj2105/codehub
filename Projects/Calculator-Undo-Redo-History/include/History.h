#ifndef HISTORY_H
#define HISTORY_H

#include "Operations.h" // For Operation struct
#include <vector>       // For storing operations
#include <iostream>     // For printing

// Class to store the last 5 operations performed
class History
{
private:
    std::vector<Operation> recent; // Vector to store recent operations
    const size_t MAX_HISTORY = 5;  // Max history size

public:
    // Add a new operation to the history
    void add(const Operation &op);

    // Display all recent operations in order
    void display() const;

    // Check if history is empty
    bool isEmpty() const;
};

#endif // HISTORY_H