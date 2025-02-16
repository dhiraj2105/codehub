#include <bits/stdc++.h>
using namespace std;

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

// Modified insert function that takes a position parameter (left or right)
void insert(int data, string position, int parentValue)
{
    // Case 1: If the tree is empty, the new node will be the root
    if (root == NULL)
    {
        root = createNode(data); // Create a new node and set it as the root
        cout << "Inserted " << data << " as the root node." << endl;
        return; // Exit the function as the node has been inserted
    }

    // Case 2: If the tree is not empty, we need to find the correct parent node where to insert the new node
    queue<node *> q; // Create a queue to store nodes for level-order traversal (breadth-first search)
    q.push(root);    // Start with the root node in the queue

    while (!q.empty()) // Continue looping until the queue is empty
    {
        node *temp = q.front(); // Get the node at the front of the queue
        q.pop();                // Remove the node from the queue

        // Check if this node is the parent node where we want to insert the new node
        if (temp->value == parentValue)
        {
            if (position == "left" && temp->left == NULL)
            {
                temp->left = createNode(data); // Insert the new node as the left child
                cout << "Inserted " << data << " as the left child of " << temp->value << "." << endl;
                return; // Exit the function after insertion
            }
            else if (position == "right" && temp->right == NULL)
            {
                temp->right = createNode(data); // Insert the new node as the right child
                cout << "Inserted " << data << " as the right child of " << temp->value << "." << endl;
                return; // Exit the function after insertion
            }
            else
            {
                cout << "Cannot insert at " << position << " of " << temp->value << " (already occupied)." << endl;
                return;
            }
        }

        // If the parent is not found, keep traversing the tree
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }

    // If the parent node is not found (shouldn't happen if parentValue exists in the tree)
    cout << "Parent node with value " << parentValue << " not found." << endl;
}

int main()
{
    // Insert nodes into the binary tree in the following order
    insert(1, "root", -1); // Insert the first node (root node), no parent for root
    insert(2, "left", 1);  // Insert a node (this will be the left child of root)
    insert(3, "right", 1); // Insert a node (this will be the right child of root)
    insert(4, "left", 2);  // Insert a node (this will be the left child of node 2)

    // Now, insert nodes 5 and 6 on the left or right of node 4
    insert(5, "left", 4);  // Insert 5 as the left child of node 4
    insert(6, "right", 4); // Insert 6 as the right child of node 4

    // Additional test cases:
    insert(7, "left", 4);  // Insert 7 as the left child of node 4 again (should fail if left is already taken)
    insert(8, "right", 2); // Insert 8 as the right child of node 2

    return 0; // End of main function
}
