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

class Solution
{
public:
    bool isSubtree(node *root, node *subRoot)
    {
        string rootString = "#";
        getTreeString(root, rootString);

        string subRootString = "#";
        getTreeString(subRoot, subRootString);

        return rootString.find(subRootString) != string::npos;
    }

private:
    void getTreeString(node *node, string &s)
    {
        if (!node)
        {
            s += "NULL#";
            return;
        }

        s += to_string(node->value) + "#";
        getTreeString(node->left, s);
        getTreeString(node->right, s);
    }
};

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    /*
    Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

    A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.
    */

    return 0;
}