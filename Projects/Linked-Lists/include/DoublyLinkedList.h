#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class DoublyLinkedList
{
public:
    using value_type = T;

private:
    NODE<T> *head;
    NODE<T> *tail;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtStart(T value)
    {
        NODE<T> *newNode = new NODE<T>(value);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(T value)
    {
        NODE<T> *newNode = new NODE<T>(value);
        if (!tail)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAtPosition(T value, int position)
    {
        if (position <= 0)
        {
            insertAtStart(value);
            return;
        }
        NODE<T> *newNode = new NODE<T>(value);
        NODE<T> *temp = head;
        for (int i = 0; temp && i < position - 1; i++)
        {
            temp = temp->next;
        }
        if (!temp)
            return;
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
        if (!newNode->next)
            tail = newNode;
    }

    void deleteAtStart()
    {
        if (!head)
            return;
        NODE<T> *temp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete temp;
    }

    void deleteAtEnd()
    {
        if (!tail)
            return;
        NODE<T> *temp = tail;
        tail = tail->prev;
        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;
        delete temp;
    }

    void deleteAtPosition(int position)
    {
        if (position <= 0 || !head)
        {
            deleteAtStart();
            return;
        }
        NODE<T> *temp = head;
        for (int i = 0; temp && i < position; i++)
        {
            temp = temp->next;
        }
        if (!temp)
            return;
        if (temp->prev)
            temp->prev->next = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        if (temp == head)
            head = temp->next;
        if (temp == tail)
            tail = temp->prev;
        delete temp;
    }

    void displayForward()
    {
        NODE<T> *temp = head;
        while (temp)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void displayBackward()
    {
        NODE<T> *temp = tail;
        while (temp)
        {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }

    ~DoublyLinkedList()
    {
        while (head)
        {
            deleteAtStart();
        }
    }
};

#endif