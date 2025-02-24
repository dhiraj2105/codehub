#ifndef MENU_H
#define MENU_H

// Include necessary header files
#include "SinglyLinkedList.h"   // For singly linked list implementation
#include "DoublyLinkedList.h"   // For doubly linked list implementation
#include "CircularLinkedList.h" // For circular linked list implementation
#include "Utility.h"            // For colors and utility functions
#include <iostream>
#include <iomanip>

using namespace std;

class Menu
{
private:
    // Create persistent list objects that maintain data throughout program execution
    SinglyLinkedList<int> singlyList;     // Object for singly linked list
    DoublyLinkedList<int> doublyList;     // Object for doubly linked list
    CircularLinkedList<int> circularList; // Object for circular linked list

    // Function to display formatted header with title
    void displayHeader(const string &title)
    {
        cout << "\n";                            // Add spacing before header
        cout << ConsoleColor::BOLD_CYAN;         // Set color to cyan for border
        cout << "+";                             // Top-left corner
        cout << string(title.length() + 4, '='); // Top border line
        cout << "+\n";                           // Top-right corner

        cout << "|  "; // Left border with padding
        // Print title in white with cyan borders
        cout << ConsoleColor::BOLD_WHITE << title << ConsoleColor::BOLD_CYAN;
        cout << "  |\n"; // Right border with padding

        cout << "+";                                // Bottom-left corner
        cout << string(title.length() + 4, '=');    // Bottom border line
        cout << "+" << ConsoleColor::RESET << "\n"; // Bottom-right corner and reset color
    }

    // Template function to handle menu for any type of list
    template <typename ListType>
    void linkedListMenu(ListType &list)
    {
        // Declare a string to store the name of the list type
        string listType;

        // Use compile-time if statement to determine the list type
        // std::is_same_v checks if two types are identical
        // typename ListType::value_type gets the underlying data type (int in this case)
        if constexpr (std::is_same_v<ListType, SinglyLinkedList<typename ListType::value_type>>)
            // If ListType is a SinglyLinkedList<T>, set appropriate name
            listType = "Singly Linked List";
        else if constexpr (std::is_same_v<ListType, DoublyLinkedList<typename ListType::value_type>>)
            // If ListType is a DoublyLinkedList<T>, set appropriate name
            listType = "Doubly Linked List";
        else
            // If neither, it must be a CircularLinkedList<T>
            listType = "Circular Linked List";

        int choice, value, position;
        do
        {
            // Display the operations menu
            displayHeader(listType + " Operations");
            cout << "\nCurrent Operations Available:\n";
            cout << ConsoleColor::BOLD_CYAN; // Set color for menu border

            // Display menu options with box drawing characters
            cout << "┌─────────────────────────────┐\n";
            cout << "│ " << ConsoleColor::BOLD_WHITE << "1. Insert at Start          " << ConsoleColor::BOLD_CYAN << "│\n";
            cout << "│ " << ConsoleColor::BOLD_WHITE << "2. Insert at Middle         " << ConsoleColor::BOLD_CYAN << "│\n";
            cout << "│ " << ConsoleColor::BOLD_WHITE << "3. Insert at End            " << ConsoleColor::BOLD_CYAN << "│\n";
            cout << "│ " << ConsoleColor::BOLD_WHITE << "4. Delete at Start          " << ConsoleColor::BOLD_CYAN << "│\n";
            cout << "│ " << ConsoleColor::BOLD_WHITE << "5. Delete at Middle         " << ConsoleColor::BOLD_CYAN << "│\n";
            cout << "│ " << ConsoleColor::BOLD_WHITE << "6. Delete at End            " << ConsoleColor::BOLD_CYAN << "│\n";
            cout << "│ " << ConsoleColor::BOLD_WHITE << "7. Display List             " << ConsoleColor::BOLD_CYAN << "│\n";
            cout << "│ " << ConsoleColor::BOLD_WHITE << "8. Return to Main Menu      " << ConsoleColor::BOLD_CYAN << "│\n";
            cout << "└─────────────────────────────┘" << ConsoleColor::RESET << "\n";

            // Get user choice
            cout << "\nEnter your choice (1-8): " << ConsoleColor::BOLD_WHITE;
            cin >> choice;
            cout << ConsoleColor::RESET;

            // Handle user choice
            switch (choice)
            {
            case 1:
                cout << "\n┌─ Insert at Start ─┐\n";
                cout << "│ Enter value: ";
                cin >> value;
                cout << "└─────────────────┘\n";
                list.insertAtStart(value);
                Utility::printSuccess("Value inserted at start successfully!");
                break;
            case 2:
                cout << "\n┌─ Insert at Middle ─┐\n";
                cout << "│ Enter value: ";
                cin >> value;
                cout << "│ Enter position: ";
                cin >> position;
                cout << "└──────────────────┘\n";
                list.insertAtPosition(value, position);
                Utility::printSuccess("Value inserted at position " + to_string(position) + " successfully!");
                break;
            case 3:
                cout << "\n┌─ Insert at End ─┐\n";
                cout << "│ Enter value: ";
                cin >> value;
                cout << "└───────────────┘\n";
                list.insertAtEnd(value);
                Utility::printSuccess("Value inserted at end successfully!");
                break;
            case 4:
                list.deleteAtStart();
                Utility::printWarning("First element deleted successfully!");
                break;
            case 5:
                cout << "\n┌─ Delete at Position ─┐\n";
                cout << "│ Enter position: ";
                cin >> position;
                cout << "└───────────────────┘\n";
                list.deleteAtPosition(position);
                Utility::printWarning("Element at position " + to_string(position) + " deleted!");
                break;
            case 6:
                list.deleteAtEnd();
                Utility::printWarning("Last element deleted successfully!");
                break;
            case 7:
                displayHeader("Current " + listType);
                // Special handling for doubly linked list to show both directions
                if constexpr (std::is_same_v<ListType, DoublyLinkedList<typename ListType::value_type>>)
                {
                    cout << "\nForward traversal:\n";
                    list.displayForward();
                    cout << "\nBackward traversal:\n";
                    list.displayBackward();
                }
                else
                {
                    list.display();
                }
                cout << "\nPress Enter to continue...";
                cin.ignore(2);
                break;
            case 8:
                Utility::printInfo("Returning to main menu...");
                break;
            default:
                Utility::printError("Invalid choice! Please select between 1-8.");
            }

            // Pause after operation (except for returning to main menu)
            if (choice != 8)
            {
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
            }
        } while (choice != 8); // Continue until user chooses to return to main menu
    }

    // Helper functions to call linkedListMenu with specific list types
    void singlyLinkedListMenu()
    {
        linkedListOperations(singlyList);
    }

    void doublyLinkedListMenu()
    {
        linkedListOperations(doublyList);
    }

    void circularLinkedListMenu()
    {
        linkedListOperations(circularList);
    }

    // Template function to route operations to the correct list type
    template <typename T>
    void linkedListOperations(T &list)
    {
        linkedListMenu(list);
    }

public:
    // Main menu function that user interacts with
    void displayMainMenu()
    {
        int choice;
        do
        {
            // Display main menu
            displayHeader("Linked List Implementation");
            cout << "\nAvailable List Types:\n";
            cout << ConsoleColor::BOLD_CYAN;
            cout << "┌───────────────────────┐\n";
            cout << "│ " << ConsoleColor::BOLD_WHITE << "1. Singly Linked List " << ConsoleColor::BOLD_CYAN << "│\n";
            cout << "│ " << ConsoleColor::BOLD_WHITE << "2. Doubly Linked List " << ConsoleColor::BOLD_CYAN << "│\n";
            cout << "│ " << ConsoleColor::BOLD_WHITE << "3. Circular List      " << ConsoleColor::BOLD_CYAN << "│\n";
            cout << "│ " << ConsoleColor::BOLD_WHITE << "4. Exit Program       " << ConsoleColor::BOLD_CYAN << "│\n";
            cout << "└───────────────────────┘" << ConsoleColor::RESET << "\n";

            // Get user choice
            cout << "\nEnter your choice (1-4): " << ConsoleColor::BOLD_WHITE;
            cin >> choice;
            cout << ConsoleColor::RESET;

            // Handle user choice
            switch (choice)
            {
            case 1:
                singlyLinkedListMenu();
                break;
            case 2:
                doublyLinkedListMenu();
                break;
            case 3:
                circularLinkedListMenu();
                break;
            case 4:
                Utility::printSuccess("\nThank you for using the program! -> " + ConsoleColor::BOLD_WHITE + "DHIRAJ KUMAR " + ConsoleColor::RESET + "https://github.com/dhiraj2105/codehub");
                break;
            default:
                Utility::printError("Invalid choice! Please select between 1-4.");
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
            }
        } while (choice != 4);
    }
};

template <typename T>
struct get_value_type
{
    using type = T;
};

template <template <typename> class Container, typename T>
struct get_value_type<Container<T>>
{
    using type = T;
};

// Template instantiations for the compiler
template void Menu::linkedListMenu(SinglyLinkedList<int> &);
template void Menu::linkedListMenu(DoublyLinkedList<int> &);
template void Menu::linkedListMenu(CircularLinkedList<int> &);

template void Menu::linkedListOperations(SinglyLinkedList<int> &);
template void Menu::linkedListOperations(DoublyLinkedList<int> &);
template void Menu::linkedListOperations(CircularLinkedList<int> &);

#endif
