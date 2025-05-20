#ifndef OPERATION_H
#define OPERATION_H

#include <string>

// structure to store one calculator oepration
struct Operation
{
    double operand1;
    double operand2;
    char op;
    double result;

    // Constructor to initialize an operation easily
    Operation(double a, double b, char oper, double res)
        : operand1(a), operand2(b), op(oper), result(res) {}

    // Converts operation into readable string format
    std::string toString() const
    {
        return std::to_string(operand1) + " " + op + " " + std::to_string(operand2) + " = " + std::to_string(result);
    }
};

#endif