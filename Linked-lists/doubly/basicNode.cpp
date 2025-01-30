#include <bits/stdc++.h>
using namespace std;

// Define structure for the node of the doubly linked list
struct Node
{
    int data;   // Stores data
    Node *next; // Pointer to the next node
    Node *prev; // Pointer to the previous node
};

// Global head pointer, initially nullptr (indicating an empty list)
Node *head = nullptr;

int main()
{
    // Step 1: Create the first node (newNode)
    Node *newNode = new Node();
    newNode->data = 10;
    newNode->next = nullptr; // Set next to nullptr, because this is the last node initially
    newNode->prev = nullptr; // No previous node yet, as this is the first node

    // Step 2: Set head to point to the first node
    head = newNode;

    // Step 3: Create the second node (newNode2)
    Node *newNode2 = new Node();
    newNode2->data = 20;
    newNode2->next = nullptr; // Set next to nullptr, as it will be the last node after linking
    newNode2->prev = newNode; // Set prev of newNode2 to point to the first node (newNode)

    // Step 4: Link the first node to the second node
    newNode->next = newNode2; // Set next of first node to point to the second node

    // Step 5: Print the linked list in forward direction (from head to tail)
    Node *current = head; // Start from the head (first node)
    cout << "Doubly Linked List (Forward): ";
    while (current != nullptr)
    {
        cout << current->data << " "; // Print the current node's data
        current = current->next;      // Move to the next node
    }
    cout << endl;

    // Step 6: Print the linked list in backward direction (from tail to head)
    // First, move to the last node (tail)
    current = head;
    while (current->next != nullptr)
    {
        current = current->next; // Traverse to the last node (tail)
    }

    // Now print from tail to head using the prev pointers
    cout << "Doubly Linked List (Backward): ";
    while (current != nullptr)
    {
        cout << current->data << " "; // Print the current node's data
        current = current->prev;      // Move to the previous node
    }
    cout << endl;

    return 0;
}
