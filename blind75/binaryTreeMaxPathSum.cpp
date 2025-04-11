#include <iostream>
#include <queue>
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

// Insert function for a general binary tree (level-order insertion)
TreeNode *insert(TreeNode *root, int key)
{
    TreeNode *newNode = new TreeNode(key);
    if (root == nullptr)
    {
        return newNode;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();

        if (temp->left == nullptr)
        {
            temp->left = newNode;
            break;
        }
        else
        {
            q.push(temp->left);
        }

        if (temp->right == nullptr)
        {
            temp->right = newNode;
            break;
        }
        else
        {
            q.push(temp->right);
        }
    }

    return root;
}

int maxPathSum(TreeNode *root)
{
}

int main()
{
    /*
    A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

    The path sum of a path is the sum of the node's values in the path.

    Given the root of a binary tree, return the maximum path sum of any non-empty path.
    */

    TreeNode *root = nullptr;

    vector<int> vals = {-10, 9, 20, 15, 7};
    for (int val : vals)
    {
        root = insert(root, val);
    }

    cout << " Maximum Path Sum : " << maxPathSum(root) << endl;

    return 0;
}