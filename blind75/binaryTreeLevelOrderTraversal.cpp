#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructor to initialize node with no childern (default)
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor to initialize with a value ( default left and right are null)
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor to initialize node with a value and childrens
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> result;

    if (!root)
    {
        return result;
    } // if tree is empty, return empty result

    queue<TreeNode *> q; // queue for traversal
    q.push(root);        // add root to queue

    while (!q.empty())
    {
        int levelSize = q.size(); // get the number of nodes at current level
        vector<int> levelNodes;   // vector to store nodes at the current level

        // process all nodes at current level
        for (int i = 0; i < levelSize; i++)
        {
            TreeNode *node = q.front(); // Get the node at front of queue
            q.pop();
            levelNodes.push_back(node->val); // add node value to levelNodes

            // add left and right childre of current node (if exist)
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        result.push_back(levelNodes); // add levelNodes to result
    }

    return result;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> res = levelOrder(root);

    for (const auto &level : res)
    {
        for (int val : level)
        {
            cout << val << " | ";
        }
    }

    return 0;
}