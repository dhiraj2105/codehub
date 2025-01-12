#include <bits/stdc++.h>
using namespace std;

// Define a struct to represent a node in the linked list
struct NODE
{
    int data;
    NODE *next;
};
NODE *head = nullptr;

NODE *createNode(int value)
{
    NODE *newNode = new NODE(); // Dynamically allocate memory for the new node
    newNode->data = value;
    newNode->next = nullptr;

    // Check if the linked list is empty
    if (head == nullptr)
    {
        // If the list is empty, set the new node as the head
        head = newNode;
    }
    else
    {
        // If the list is not empty, traverse to the last node
        NODE *temp = head;
        // Traverse the list until the last node is reached
        while (temp->next != nullptr)
        {
            // Move to the next node
            temp = temp->next;
        }
        // Set the last node's next pointer to the new node
        temp->next = newNode;
    }

    return newNode;
}

// Function to print the linked list
void printList(NODE *node)
{
    while (node != nullptr)
    {
        cout << node->data << " ";
        // Move to the next node
        node = node->next;
    }
    cout << "null" << endl;
}

// Function to insert a new node at the beginning of the linked list
NODE *insertAtBeginning(int value)
{
    // Dynamically allocate memory for the new node
    NODE *newNode = new NODE();
    newNode->data = value;
    // Set the new node's next pointer to the current head
    newNode->next = head;
    // Update the head to point to the new node
    head = newNode;

    // Return the newly created node
    return newNode;
}

int main()
{
    createNode(1);
    createNode(2);
    createNode(3);
    createNode(4);

    // Print the original linked list
    cout << "-> Original linked list : ";
    printList(head);

    // Insert a new node with value 11 at the beginning of the list
    cout << "-> Modified linked list : ";
    insertAtBeginning(11);
    printList(head);

    return 0;
}