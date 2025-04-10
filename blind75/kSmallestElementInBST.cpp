#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *root = nullptr;

// Insert a node into BST
TreeNode *insert(TreeNode *root, int val)
{
    if (root == nullptr)
        return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

int KthSmallest(TreeNode *root, int k)
{
    // find using inorder traversal
    stack<TreeNode *> myStack;
    TreeNode *current = root;

    while (current || !myStack.empty())
    {
        while (current)
        {
            myStack.push(current);
            current = current->left;
        }
        current = myStack.top();
        myStack.pop();
        if (--k == 0)
        {
            return current->val;
        }
        current = current->right;
    }
    return -1;
}

int main()
{
    /*
    Given the root of binary search tree, and an integer k, return the Kth smallest value (1-indexed) of all the values of nodes in tree.
    */

    vector<int> vals = {4, 1, 3, 2};
    for (int val : vals)
    {
        root = insert(root, val);
    }

    int k = 1;
    cout << " Kth Smallest Element in BST : " << KthSmallest(root, k) << endl;

    return 0;
}