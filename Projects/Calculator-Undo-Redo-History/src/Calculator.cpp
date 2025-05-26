#include "Calculator.h"

// Function to add numbers
double Calculator::add(double a, double b)
{
    return a + b;
}

// Function to subtract second number from first
double Calculator::subtract(double a, double b)
{
    return a - b; // Simple subtraction
}

// Function to multiply two numbers
double Calculator::multiply(double a, double b)
{
    return a * b; // Simple multiplication
}

// Function to divide a by b, sets success = false if b == 0
double Calculator::divide(double a, double b, bool &success)
{
    if (b == 0)
    {                    // Check if divisor is zero
        success = false; // Set failure flag
        return 0.0;      // Return default value
    }
    success = true; // Set success flag
    return a / b;   // Perform division
}

// Function to perform a % b manually
int Calculator::modulo(int a, int b, bool &success)
{
    if (b == 0)
    {                    // Check for divide-by-zero
        success = false; // Set failure flag
        return 0;        // Return default value
    }

    success = true; // Set success flag

    // Manual modulo implementation (a - (a/b)*b)
    int quotient = a / b;      // Get integer quotient
    return a - (quotient * b); // Return remainder
}

// Function to compute base raised to exponent manually
double Calculator::power(double base, int exponent)
{
    double result = 1.0;     // Start with 1
    bool isNegative = false; // Flag for negative exponent

    if (exponent < 0)
    {                         // If exponent is negative
        isNegative = true;    // Mark negative
        exponent = -exponent; // Convert to positive
    }

    // Multiply base exponent times
    for (int i = 0; i < exponent; ++i)
    {
        result *= base; // Multiply result by base
    }

    if (isNegative)
    {
        return 1.0 / result; // Return reciprocal if exponent was negative
    }

    return result; // Return final result
}