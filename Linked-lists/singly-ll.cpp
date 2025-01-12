#include <bits/stdc++.h>
using namespace std;

// Define a structure for a node in the linked list
struct NODE
{
    int data;   // Data stored in the node
    NODE *next; // Pointer to the next node in the list
};

// Global head pointer to the start of the linked list
NODE *head = nullptr;

// Function to create a new node and add it to the linked list
NODE *create(int value)
{
    // Allocate memory for a new node
    NODE *new_node = new NODE;
    // Set the data of the new node to the provided value
    new_node->data = value;
    // Initialize the next pointer of the new node to nullptr
    new_node->next = nullptr;

    // If the linked list is empty (head is nullptr), make the new node the head
    if (head == nullptr)
    {
        head = new_node;
    }
    else
    {
        // If the list is not empty, traverse to the end of the list
        NODE *temp = head; // Start from the head
        while (temp->next != nullptr)
        {
            temp = temp->next; // Move to the next node
        }

        // Add the new node at the end of the list
        temp->next = new_node;
    }

    // Return the newly created node
    return new_node;
}

// Function to print the linked list
void printList(NODE *node)
{
    cout << "The data in the linked list is: ";
    while (node != nullptr) // Traverse the list until the end
    {
        cout << node->data << " | "; // Print the data of the current node
        node = node->next;           // Move to the next node
    }
    cout << "nullptr" << endl;
}

int main()
{
    create(10);
    create(0);
    create(50);
    create(1);

    printList(head);

    return 0;
}