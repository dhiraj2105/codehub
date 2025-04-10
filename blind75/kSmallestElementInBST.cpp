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

// Find kth smallest element in a BST using iterative inorder traversal
int KthSmallest(TreeNode *root, int k)
{
    // Stack to simulate recursion for inorder traversal
    stack<TreeNode *> st;

    TreeNode *curr = root;

    // Loop until we've traversed all nodes
    while (curr || !st.empty())
    {
        // Go as left as possible (smallest values in BST are on the left)
        while (curr)
        {
            st.push(curr);     // Save current node to come back to it later
            curr = curr->left; // Move to left child
        }

        // Process node at the top of the stack
        curr = st.top();
        st.pop(); // Visit the leftmost unvisited node

        // Decrement k since we're visiting one more node in sorted order
        if (--k == 0)
            return curr->val; // If k reaches 0, we've found the kth smallest

        // Move to right subtree (larger values)
        curr = curr->right;
    }

    // If k is larger than the number of nodes in the BST
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