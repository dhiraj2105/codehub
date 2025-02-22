#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
using namespace std;

namespace ConsoleColor
{
    // Regular text
    const string BLACK = "\033[0;30m";
    const string RED = "\033[0;31m";     // Errors or deletions
    const string GREEN = "\033[0;32m";   // Success or additions
    const string YELLOW = "\033[0;33m";  // Warnings or changes
    const string BLUE = "\033[0;34m";    // Information or notes
    const string MAGENTA = "\033[0;35m"; // Special Info
    const string CYAN = "\033[0;36m";    // Additional info
    const string WHITE = "\033[0;37m";

    // Bold text
    const string BOLD_BLACK = "\033[1;30m";
    const string BOLD_RED = "\033[1;31m";
    const string BOLD_GREEN = "\033[1;32m";
    const string BOLD_YELLOW = "\033[1;33m";
    const string BOLD_BLUE = "\033[1;34m";
    const string BOLD_MAGENTA = "\033[1;35m";
    const string BOLD_CYAN = "\033[1;36m";
    const string BOLD_WHITE = "\033[1;37m";

    // Reset
    const string RESET = "\033[0m";
}

class Utility
{
public:
    static void printSuccess(const string &message)
    {
        cout << ConsoleColor::BOLD_GREEN << "✓ " << message << ConsoleColor::RESET << endl;
    }
    static void printError(const string &message)
    {
        cout << ConsoleColor::BOLD_RED << "✗ " << message << ConsoleColor::RESET << endl;
    }

    static void printInfo(const string &message)
    {
        cout << ConsoleColor::BOLD_BLUE << "ℹ " << message << ConsoleColor::RESET << endl;
    }

    static void printWarning(const string &message)
    {
        cout << ConsoleColor::BOLD_YELLOW << "⚠ " << message << ConsoleColor::RESET << endl;
    }
};

#endif