#include "History.h"

// Add a new operation to the history
void History::add(const Operation &op)
{
    // If history has reached its max size
    if (recent.size() == MAX_HISTORY)
    {
        recent.erase(recent.begin()); // Remove the oldest operation (first element)
    }

    recent.push_back(op); // Add new operation at the end
}

// Display all recent operations
void History::display() const
{
    if (recent.empty())
    {
        std::cout << "No history available.\n"; // Show if history is empty
        return;
    }

    std::cout << "Recent Operations:\n";

    // Loop through the history vector
    for (size_t i = 0; i < recent.size(); ++i)
    {
        std::cout << i + 1 << ". " << recent[i].toString() << "\n"; // Print each operation
    }
}

// Check if the history is empty
bool History::isEmpty() const
{
    return recent.empty(); // Return true if vector is empty
}
