#include <bits/stdc++.h>
using namespace std;

/*
A binary tree is a tree data structure in which each node has at most two children (i.e, left child and right child).
1. The nodes with no children are called leaf nodes.
2. The first node is the root node.
3. The nodes that are not the root but have children are called internal nodes.

To implement the Binary Tree without using classes, we'll do something similar to how we handle Linked Lists:
1. Create a data type (struct) for a node, which will hold pointers for left and right children and the data (value) for the node.
2. Use a root pointer to represent the root of the tree and store the address of the root node.
*/

// Define the structure for a node in the binary tree
struct node
{
    node *left;  // Pointer to the left child of the node
    int value;   // Data stored in the node
    node *right; // Pointer to the right child of the node
};

// Declare a root pointer, initially set to NULL, meaning the tree is empty
struct node *root = NULL;

// Function to create a new node with a specific value
node *createNode(int data)
{
    node *newNode = new node();            // Create a new node dynamically using 'new' keyword
    newNode->value = data;                 // Set the value of the node
    newNode->left = newNode->right = NULL; // Initially set both left and right child pointers to NULL (no children)
    return newNode;                        // Return the newly created node
}

// Function to insert a node into the binary tree
void insert(int data)
{
    // Case 1: If the tree is empty, the new node will be the root
    if (root == NULL)
    {
        root = createNode(data); // Create a new node and set it as the root
        return;                  // Exit the function as the node has been inserted
    }

    // Case 2: If the tree is not empty, we need to find the correct position for the new node
    queue<node *> q; // Create a queue to store nodes for level-order traversal (breadth-first search)
    q.push(root);    // Start with the root node in the queue

    while (!q.empty()) // Continue looping until the queue is empty
    {
        node *temp = q.front(); // Get the node at the front of the queue
        q.pop();                // Remove the node from the queue

        // Check if the left child of the current node is NULL (empty)
        if (temp->left == NULL)
        {
            temp->left = createNode(data); // Insert the new node as the left child
            return;                        // Exit the function after insertion
        }
        else
        {
            q.push(temp->left); // If the left child exists, push it to the queue for further checking
        }

        // Check if the right child of the current node is NULL (empty)
        if (temp->right == NULL)
        {
            temp->right = createNode(data); // Insert the new node as the right child
            return;                         // Exit the function after insertion
        }
        else
        {
            q.push(temp->right); // If the right child exists, push it to the queue for further checking
        }
    }
}

int main()
{
    // Insert nodes into the binary tree in the following order
    insert(1); // Insert the first node (root node)
    insert(2); // Insert a node (this will be the left child of root)
    insert(3); // Insert a node (this will be the right child of root)
    insert(4); // Insert a node (this will be the left child of node 2)
    insert(5); // Insert a node (this will be the right child of node 2)

    // The tree structure now looks like this:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    return 0; // End of main function
}
