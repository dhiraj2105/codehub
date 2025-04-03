#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode *left;
    TreeNode *right;

    // Constructor to create a node with a value
    TreeNode(T value)
    {
        val = value;
        left = nullptr;
        right = nullptr;
    }

    // Constructor to create a node with a value and optional left and right children
    TreeNode(T value, TreeNode *leftChild, TreeNode *rightChild)
    {
        val = value;
        left = leftChild;
        right = rightChild;
    }

    // Destructor to free the left and right child nodes
    ~TreeNode()
    {
        delete left;
        delete right;
    }
};

template <typename T>
class BinarySearchTree
{
private:
    TreeNode<T> *root;

    // Helper function to insert values into the binary search tree
    TreeNode<T> *insertHelper(TreeNode<T> *node, T value)
    {
        if (node == nullptr)
        {
            return new TreeNode<T>(value); // Create a new node
        }
        if (value < node->val)
        {
            node->left = insertHelper(node->left, value); // Insert in left subtree
        }
        else if (value > node->val)
        {
            node->right = insertHelper(node->right, value); // Insert in right subtree
        }
        return node; // Return the updated node
    }

    // Helper function to validate if the binary tree is a valid BST
    bool isValidBinarySearchTree(TreeNode<T> *root)
    {
        // Call the helper function with initial min and max values set to the smallest and largest possible values
        return checkBST(root, INT64_MIN, INT64_MAX);
    }

    // Helper function to validate the BST by checking the allowed value range for each node
    bool checkBST(TreeNode<T> *root, long long min, long long max)
    {
        // Base case: If the node's value is not within the allowed range, it's not a valid BST
        if (root->val <= min || root->val >= max)
            return false;

        // Recursively check the left subtree with an updated max value (should be less than the current node's value)
        bool left = root->left ? checkBST(root->left, min, root->val) : true;

        // Recursively check the right subtree with an updated min value (should be greater than the current node's value)
        bool right = root->right ? checkBST(root->right, root->val, max) : true;

        // The tree is a valid BST only if both left and right subtrees are valid
        return left && right;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // Insert a value into the binary search tree
    void insert(T value)
    {
        root = insertHelper(root, value);
    }

    // Check if the tree is a valid binary search tree
    bool isValidBST()
    {
        return isValidBinarySearchTree(root);
    }
};

int main()
{
    // Create a BST
    BinarySearchTree<int> bst;

    // Insert values into the BST
    bst.insert(2);
    bst.insert(1);
    bst.insert(3);

    // Check if the tree is a valid BST
    if (bst.isValidBST())
    {
        std::cout << "The binary search tree is valid." << std::endl;
    }
    else
    {
        std::cout << "The binary search tree is not valid." << std::endl;
    }

    return 0;
}
