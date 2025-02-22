#include "DoublyLinkedList.h"

// insert at start
template <typename T>
void DoublyLinkedList<T>::insertAtStart(T value)
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

// insert at end
template <typename T>
void DoublyLinkedList<T>::insertAtEnd(T value)
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

// Insert at a specific position
template <typename T>
void DoublyLinkedList<T>::insertAtPosition(T value, int position)
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

// Delete at the start
template <typename T>
void DoublyLinkedList<T>::deleteAtStart()
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

// Delete at the end
template <typename T>
void DoublyLinkedList<T>::deleteAtEnd()
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

// Delete at a specific position
template <typename T>
void DoublyLinkedList<T>::deleteAtPosition(int position)
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

// Display the linked list forward
template <typename T>
void DoublyLinkedList<T>::displayForward()
{
    NODE<T> *temp = head;
    while (temp)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Display the linked list backward
template <typename T>
void DoublyLinkedList<T>::displayBackward()
{
    NODE<T> *temp = tail;
    while (temp)
    {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

// Destructor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    while (head)
    {
        deleteAtStart();
    }
}