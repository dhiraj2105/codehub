#ifndef MENU_H
#define MENU_H

#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
#include "Utility.h"
#include <iostream>

using namespace std;

class Menu
{

private:
    template <typename T>
    void linkedListOperations(SinglyLinkedList<T> &list)
    {
        linkedListMenu(list);
    }

    template <typename T>
    void linkedListOperations(DoublyLinkedList<T> &list)
    {
        linkedListMenu(list);
    }

    template <typename T>
    void linkedListOperations(CircularLinkedList<T> &list)
    {
        linkedListMenu(list);
    }

    template <typename ListType>
    void linkedListMenu(ListType &list)
    {
        int choice, value, position;
        do
        {
            Utility::printInfo("\n--- Operations Menu ---");
            cout << "1. Insert at Start" << endl;
            cout << "2. Insert at Middle" << endl;
            cout << "3. Insert at End" << endl;
            cout << "4. Delete at Start" << endl;
            cout << "5. Delete at Middle" << endl;
            cout << "6. Delete at End" << endl;
            cout << "7. Display" << endl;
            cout << "8. Exit to Main Menu" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtStart(value);
                Utility::printSuccess("Inserted at start successfully.");
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                list.insertAtPosition(value, position);
                Utility::printSuccess("Inserted in middle successfully.");
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtEnd(value);
                Utility::printSuccess("Inserted at end successfully.");
                break;
            case 4:
                list.deleteAtStart();
                Utility::printWarning("Deleted from start.");
                break;
            case 5:
                cout << "Enter position to delete: ";
                cin >> position;
                list.deleteAtPosition(position);
                Utility::printWarning("Deleted from middle.");
                break;
            case 6:
                list.deleteAtEnd();
                Utility::printWarning("Deleted from end.");
                break;
            case 7:
                Utility::printInfo("Displaying list:");
                list.display();
                break;
            case 8:
                Utility::printInfo("Returning to main menu.");
                break;
            default:
                Utility::printError("Invalid choice. Try again.");
            }
        } while (choice != 8);
    }

    void singlyLinkedListMenu()
    {
        SinglyLinkedList<int> list;
        linkedListOperations(list);
    }

    void doublyLinkedListMenu()
    {
        DoublyLinkedList<int> list;
        linkedListOperations(list);
    }

    void circularLinkedListMenu()
    {
        CircularLinkedList<int> list;
        linkedListOperations(list);
    }

public:
    void displayMainMenu()
    {
        int choice;
        do
        {
            Utility::printInfo("\n===== Linked List Menu =====");
            cout << "1. Singly Linked List" << endl;
            cout << "2. Doubly Linked List" << endl;
            cout << "3. Circular Linked List" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

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
                Utility::printSuccess("Exiting the program.");
                break;
            default:
                Utility::printError("Invalid choice. Try again.");
            }
        } while (choice != 4);
    }
};

#endif