#include <bits/stdc++.h>
#include "utility.h"
using namespace std;

extern void stackMenu();
extern void queueMenu();
extern void dequeMenu();

void mainMenu()
{
    int choice;
    do
    {
        Utility::printInfo("===== Main Menu =====");
        cout
            << "1. Stack\n2. Queue\n3. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            stackMenu();
            break;
        case 2:
            int qchoice;
            cout << "Which queue you want to use ? \n 1. Normal queue \n 2. Double Ended queue ";
            cin >> qchoice;
            if (qchoice == 1)
            {
                queueMenu();
            }
            else if (qchoice == 2)
            {
                dequeMenu();
            }
            break;
        case 3:
            Utility::printSuccess("\nThank you for using the program! -> " + ConsoleColor::BOLD_WHITE + "DHIRAJ KUMAR " + ConsoleColor::RESET + "https://github.com/dhiraj2105/codehub");
            break;
        default:
            Utility::printError("Invalid choice");
        }
    } while (choice != 3);
}

int main()
{
    Utility::printInfo("\n===== Welcome to the program =====");
    mainMenu();
    return 0;
}