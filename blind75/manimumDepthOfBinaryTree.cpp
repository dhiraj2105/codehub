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

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main()
{
    Solution solution;

    // Test Case 1:
    //     3
    //    / \
    //   9  20
    //     /  \
    //    15   7
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    cout << "Maximum Depth of Test Case 1: " << solution.maxDepth(root1) << endl;

    // Test Case 2:
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);
    cout << "Maximum Depth of Test Case 2: " << solution.maxDepth(root2) << endl;

    // Test Case 3:
    //     1
    TreeNode *root3 = new TreeNode(1);
    cout << "Maximum Depth of Test Case 3: " << solution.maxDepth(root3) << endl;

    // Test Case 4:
    //     (empty tree)
    TreeNode *root4 = nullptr;
    cout << "Maximum Depth of Test Case 4: " << solution.maxDepth(root4) << endl;

    return 0;
}