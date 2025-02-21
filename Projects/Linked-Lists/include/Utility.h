#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
using namespace std;

namespace ConsoleColor
{
    const string RESET = "\033[0m]";
    const string RED = "\033[31m]";     // Errors or deletions
    const string GREEN = "\033[32m]";   // Success or additions
    const string YELLOW = "\033[33m]";  // Warnings or changes
    const string BLUE = "\033[34m]";    // Information or notes
    const string MAGENTA = "\033[35m]"; // Special Info
    const string CYAN = "\033[36m]";    // Additional info
}

class Utility
{
public:
    static void printSuccess(const string &message)
    {
        cout << ConsoleColor::GREEN << message << ConsoleColor::RESET << endl;
    }
    static void printError(const string &message)
    {
        cout << ConsoleColor::RED << message << ConsoleColor::RESET << endl;
    }

    static void printInfo(const string &message)
    {
        cout << ConsoleColor::BLUE << message << ConsoleColor::RESET << endl;
    }

    static void printWarning(const string &message)
    {
        cout << ConsoleColor::YELLOW << message << ConsoleColor::RESET << endl;
    }
};

#endif