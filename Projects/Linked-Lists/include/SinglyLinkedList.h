#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include "Node.h"
#include <iostream>
using namespace std;

// Template class for singly LL
template <typename T>

class SinglyLinkedList
{
public:
    using value_type = T;

private:
    NODE<T> *head; // head pointer to first node of data type t
public:
    SinglyLinkedList() { head = nullptr; }

    // Function prototypes
    void insertAtStart(T value)
    {
        NODE<T> *newNode = new NODE<T>(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(T value)
    {
        NODE<T> *newNode = new NODE<T>(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        NODE<T> *current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    void insertAtPosition(T value, int position)
    {
        if (position <= 0)
        {
            insertAtStart(value);
            return;
        }
        NODE<T> *newNode = new NODE<T>(value);
        NODE<T> *current = head;
        for (int i = 0; current && i < position - 1; i++)
        {
            current = current->next;
        }
        if (!current)
            return;
        newNode->next = current->next;
        current->next = newNode;
    }

    void deleteAtStart()
    {
        if (!head)
            return;
        NODE<T> *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd()
    {
        if (!head)
            return;
        if (!head->next)
        {
            delete head;
            head = nullptr;
            return;
        }
        NODE<T> *temp = head;
        while (temp->next->next)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteAtPosition(int position)
    {
        if (position <= 0 || !head)
        {
            deleteAtStart();
            return;
        }
        NODE<T> *current = head;
        for (int i = 0; current->next && i < position - 1; i++)
        {
            current = current->next;
        }
        if (!current->next)
            return;
        NODE<T> *temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    void display()
    {
        NODE<T> *current = head;
        while (current)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free memory
    ~SinglyLinkedList()
    {
        while (head)
        {
            deleteAtStart();
        }
    }
};

#endif