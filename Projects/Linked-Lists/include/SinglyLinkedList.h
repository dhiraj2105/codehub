#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include "Node.h"
#include <iostream>
using namespace std;

// Template class for singly LL
template <typename T>

class SinglyLinkedList
{
private:
    NODE<T> *head; // head pointer to first node of data type t
public:
    SinglyLinkedList(); // constructor

    // Function prototypes
    void insertAtStart(T value);
    void insertAtEnd(T value);
    void insertAtPosition(T value, int position);
    void deleteAtStart();
    void deleteAtEnd();
    void deleteAtPosition(int position);
    void display();

    // Destructor to free memory
    ~SinglyLinkedList();
};

#endif