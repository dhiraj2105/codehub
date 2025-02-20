#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "Node.h"
#include <iostream>
using namespace std;

// Template class for Doubly LL
template <typename T>

class DoublyLinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // function prototypes
    void insertAtStart(T value);
    void insertAtEnd(T value);
    void insertAtPosition(T value, int position);
    void deleteAtStart();
    void deleteAtEnd();
    void deleteAtPosition(int position);
    void displayForward();
    void displayBackward();

    ~DoublyLinkedList();
};

#endif