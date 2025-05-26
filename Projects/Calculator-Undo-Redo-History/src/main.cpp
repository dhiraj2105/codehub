#include <iostream>         // For input/output
#include "Calculator.h"     // Arithmetic logic
#include "Operations.h"     // Operation structure
#include "OperationStack.h" // Undo/Redo stack
#include "History.h"        // History of operations
#include "Utils.h"

void showMenu()
{
    std::cout << Color::CYAN << "\n--- Calculator Menu ---\n"
              << Color::RESET;
    std::cout << "1. Perform Operation\n";
    std::cout << "2. Undo\n";
    std::cout << "3. Redo\n";
    std::cout << "4. View History\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
}

Operation getOperationFromUser()
{
    double a, b;
    char op;

    std::cout << "Enter first operand: ";
    std::cin >> a;

    std::cout << "Enter operator (+, -, *, /, %, ^): ";
    std::cin >> op;

    std::cout << "Enter second operand: ";
    std::cin >> b;

    double result = 0.0;
    bool success = true;

    // Manually handle the operation
    switch (op)
    {
    case '+':
        result = Calculator::add(a, b);
        break;
    case '-':
        result = Calculator::subtract(a, b);
        break;
    case '*':
        result = Calculator::multiply(a, b);
        break;
    case '/':
        result = Calculator::divide(a, b, success);
        if (!success)
            std::cout << Color::RED << "Error: Division by zero!\n"
                      << Color::RESET;
        break;
    case '%':
        result = Calculator::modulo((int)a, (int)b, success);
        if (!success)
            std::cout << Color::RED << "Error: Modulo by zero!\n"
                      << Color::RESET;
        break;
    case '^':
        result = Calculator::power(a, (int)b);
        break;
    default:
        std::cout << Color::RED << "Invalid operator!\n"
                  << Color::RESET;
        success = false;
        break;
    }

    // Return a dummy result if failed
    if (!success)
    {
        return Operation(0, 0, '?', 0);
    }

    return Operation(a, b, op, result);
}

int main()
{
    OperationStack undoStack; // For undo functionality
    OperationStack redoStack; // For redo functionality
    History history;          // For recent 5 operations

    int choice;

    while (true)
    {
        showMenu();         // Show options
        std::cin >> choice; // Read user input

        if (choice == 1)
        { // Perform operation
            Operation op = getOperationFromUser();

            if (op.op != '?')
            { // If valid
                std::cout << Color::GREEN << "Result: " << op.result << "\n"
                          << Color::RESET;
                undoStack.push(op); // Save to undo stack
                redoStack.clear();  // Clear redo stack (new op resets redo)
                history.add(op);    // Add to history
            }
        }
        else if (choice == 2)
        { // Undo
            if (undoStack.isEmpty())
            {
                std::cout << Color::YELLOW << "Nothing to undo.\n"
                          << Color::RESET;
            }
            else
            {
                Operation last = undoStack.pop(); // Remove last op
                redoStack.push(last);             // Push to redo
                std::cout << Color::MAGENTA << "Undo: " << last.toString() << "\n"
                          << Color::RESET;
            }
        }
        else if (choice == 3)
        { // Redo
            if (redoStack.isEmpty())
            {
                std::cout << Color::YELLOW << "Nothing to redo.\n"
                          << Color::RESET;
            }
            else
            {
                Operation redoOp = redoStack.pop(); // Remove from redo
                undoStack.push(redoOp);             // Push back to undo
                history.add(redoOp);                // Save to history
                std::cout << Color::GREEN << "Redo: " << redoOp.toString() << "\n"
                          << Color::RESET;
            }
        }
        else if (choice == 4)
        { // History
            history.display();
        }
        else if (choice == 5)
        { // Exit
            std::cout << Color::BLUE << "Goodbye!\n"
                      << Color::RESET;
            break;
        }
        else
        {
            std::cout << Color::RED << "Invalid choice.\n"
                      << Color::RESET;
        }
    }

    return 0;
}