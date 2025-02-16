#include <bits/stdc++.h>
using namespace std;

/*
A binary tree is a tree data structure in which each node has at most two children (i.e, left child and right child).
1. The nodes with no children are called leaf nodes.
2. First Node is root node.
3. The nodes which are not root but have children are called internal nodes.


To implement Binary Tree without classes , we will do similar to Linked List :
1. Create data type node, having left and right pointer and data.
2. Create a root/head and store root node's address to it.
*/

struct node
{
    node *left; // left side child
    int value;
    node *right; // right side child
};

// root pointer to root node
struct node *root = NULL;

node *createNode(int data)
{
    node *newNode = new node();
    newNode->value = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(int data)
{
    // if tree is empty , new node will be the root
    if (root == NULL)
    {
        root = createNode(data);
        return;
    }
    // if tree is not empty, we perform insertion
    queue<node *> q; // create a queue to store nodes for level-order traversal
    q.push(root);    // start with root node
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp->left == NULL)
        {
            temp->left = createNode(data);
            return;
        }
        else
        {
            q.push(temp->left);
        }
        if (temp->right == NULL)
        {
            temp->right = createNode(data);
            return;
        }
        else
        {
            q.push(temp->right);
        }
    }
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    return 0;
}