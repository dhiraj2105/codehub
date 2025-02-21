#ifndef MENU_H
#define MENU_H

#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
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
            cout << "\n--- Operations Menu ---" << endl;
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
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                list.insertAtPosition(value, position);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 4:
                list.deleteAtStart();
                break;
            case 5:
                cout << "Enter position to delete: ";
                cin >> position;
                list.deleteAtPosition(position);
                break;
            case 6:
                list.deleteAtEnd();
                break;
            case 7:
                list.display();
                break;
            case 8:
                cout << "Returning to main menu." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
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
            cout << "\n===== Linked List Menu =====" << endl;
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
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
            }
        } while (choice != 4);
    }
};

#endif