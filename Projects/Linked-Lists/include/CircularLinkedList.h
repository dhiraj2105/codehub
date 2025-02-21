#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include "Node.h"
#include <iostream>

using namespace std;

template <typename T>

class CircularLinkedList
{
private:
    Node<T> *tail;

public:
    CircularLinkedList()
    {
        tail = nullptr;
    }

    // Function prototypes
    void insertAtStart(T value);
    void insertAtEnd(T value);
    void insertAtPosition(T value, int position);
    void deleteAtStart();
    void deleteAtEnd();
    void deleteAtPosition(int position);
    void display();

    ~CircularLinkedList();
};

#endif