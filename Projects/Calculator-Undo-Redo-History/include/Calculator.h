#ifndef CALCULATOR_H
#define CALCULATOR_H

// Class that performs basic arithmetic operations
class Calculator
{
public:
    // Perform addition
    static double add(double a, double b);

    // Perform subtraction
    static double subtract(double a, double b);

    // Perform multiplication
    static double multiply(double a, double b);

    // Perform division (handle divide-by-zero manually)
    static double divide(double a, double b, bool &success);

    // Perform modulo operation manually (for integers only)
    static int modulo(int a, int b, bool &success);

    // Perform power operation manually (integer exponents only)
    static double power(double base, int exponent);
};

#endif