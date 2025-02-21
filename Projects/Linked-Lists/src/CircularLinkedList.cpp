#include "CircularLinkedList.h"

// Insert at the start
template <typename T>
void CircularLinkedList<T>::insertAtStart(T value)
{
    NODE<T> *newNode = new NODE<T>(value);
    if (!tail)
    {
        tail = newNode;
        tail->next = tail;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
    }
}

// Insert at the end
template <typename T>
void CircularLinkedList<T>::insertAtEnd(T value)
{
    NODE<T> *newNode = new NODE<T>(value);
    if (!tail)
    {
        tail = newNode;
        tail->next = tail;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

// Insert at a specific position
template <typename T>
void CircularLinkedList<T>::insertAtPosition(T value, int position)
{
    if (position <= 0 || !tail)
    {
        insertAtStart(value);
        return;
    }
    NODE<T> *temp = tail->next;
    for (int i = 0; i < position - 1 && temp != tail; i++)
    {
        temp = temp->next;
    }
    NODE<T> *newNode = new NODE<T>(value);
    newNode->next = temp->next;
    temp->next = newNode;
    if (temp == tail)
        tail = newNode;
}

// Delete at the start
template <typename T>
void CircularLinkedList<T>::deleteAtStart()
{
    if (!tail)
        return;
    NODE<T> *temp = tail->next;
    if (tail == tail->next)
    {
        delete tail;
        tail = nullptr;
    }
    else
    {
        tail->next = temp->next;
        delete temp;
    }
}

// Delete at the end
template <typename T>
void CircularLinkedList<T>::deleteAtEnd()
{
    if (!tail)
        return;
    if (tail == tail->next)
    {
        delete tail;
        tail = nullptr;
    }
    else
    {
        NODE<T> *temp = tail->next;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = tail->next;
        delete tail;
        tail = temp;
    }
}

// Delete at a specific position
template <typename T>
void CircularLinkedList<T>::deleteAtPosition(int position)
{
    if (!tail || position < 0)
        return;
    if (position == 0)
    {
        deleteAtStart();
        return;
    }
    NODE<T> *temp = tail->next;
    for (int i = 0; i < position - 1 && temp->next != tail->next; i++)
    {
        temp = temp->next;
    }
    if (temp->next == tail->next)
        return;
    NODE<T> *toDelete = temp->next;
    temp->next = toDelete->next;
    if (toDelete == tail)
        tail = temp;
    delete toDelete;
}

// Display the list
template <typename T>
void CircularLinkedList<T>::display()
{
    {
        if (!tail)
        {
            cout << "List is empty." << endl;
            return;
        }
        NODE<T> *temp = tail->next;
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "(back to start)" << endl;
    }
}

template <typename T>
CircularLinkedList<T>::~CircularLinkedList()
{
    while (tail)
    {
        deleteAtStart();
    }
}