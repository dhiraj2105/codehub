#include "SinglyLinkedList.h"
#include "Utility.h"

// insert at start
template <typename T>
void SinglyLinkedList<T>::insertAtStart(T value)
{
    NODE<T> *newNode = new NODE<T>(value);
    newNode->next = head;
    head = newNode;
    Utility::printSuccess("Inserted at the start.");
}

// insert at end
template <typename T>
void SinglyLinkedList<T>::insertAtEnd(T value)
{
    NODE<T> *newNode = new NODE<T>(value);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node<T> *current = head;
    while (current->next)
    {
        {
            current = current->next;
        }
        current->next = newNode;
    }
    Utility::printSuccess("Inserted at the end.");
}

// insert at a position
template <typename T>
void SinglyLinkedList<T>::insertAtPosition(T value, int position)
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
    {
        Utility::printError("Position out of Bounds.");
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
    Utility::printSuccess("Inserted at the specified position.");
}

// delete at start
template <typename T>
void SinglyLinkedList<T>::deleteAtStart()
{
    if (!head)
    {
        Utility::printError("List is empty.");
        return;
    }
    NODE<T> *current = head;
    head = head->next;
    delete current;
    Utility::printSuccess("Deleted at the start.");
}

// delete at end
template <typename T>
void SinglyLinkedList<T>::deleteAtEnd()
{
    if (!head)
    {
        Utility::printError("List is empty.");
        return;
    }
    if (!head->next)
    {
        delete head;
        head = nullptr;
        Utility::printSuccess("Deleted at the end.");
        return;
    }
    NODE<T> *current = head;
    while (current->next->next)
    {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
    Utility::printSuccess("Deleted at the end.");
}

// delete at a position
template <typename T>
void SinglyLinkedList<T>::deleteAtPosition(int position)
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
    {
        Utility::printError("Position out of Bounds.");
        return;
    }
    NODE<T> *deleteNode = current->next;
    current->next = current->next->next;
    delete deleteNode;
    Utility::printSuccess("Deleted at position " + std::to_string(position));
}

// display the linked list
template <typename T>
void SinglyLinkedList<T>::display()
{
    NODE<T> *current = head;
    Utility::printInfo("List contents : ");
    while (current)
    {
        std::cout << current->data << " ";
        current = current->next
    }
    std::cout << "NULL" << endl;
}

// destructure
template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    while (head)
    {
        deleteAtStart();
    }
}