#include <bits/stdc++.h>
using namespace std;

struct node
{
    node *left;
    int value;
    node *right;
};

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
    if (root == NULL)
    {
        root = createNode(data);
        return;
    }

    queue<node *> q;
    q.push(root);

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

void printingTree(node *root)
{
    // BFS - level by level
    if (root == NULL)
    {
        cout << "Tree is empty " << endl;
        return;
    }
    else
    {
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();

            cout << temp->value << " ";

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
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

    cout << "The value of tree are : ";
    printingTree(root);

    return 0;
}