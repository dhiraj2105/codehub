#include <iostream>
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

bool isSameTree(TreeNode *p, TreeNode *q)
{
    // If both trees are null, they are the same
    if (!p && !q)
        return true;

    // If one of them is null and the other is not, they are not the same
    if (!p || !q)
        return false;

    // If the values of the nodes are different, they are not the same
    if (p->val != q->val)
        return false;

    // Recursively check the left and right subtrees
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

void testCases()
{
    // Test Case 1: Both trees are the same
    TreeNode *p1 = new TreeNode(1);
    p1->left = new TreeNode(2);
    p1->right = new TreeNode(3);

    TreeNode *q1 = new TreeNode(1);
    q1->left = new TreeNode(2);
    q1->right = new TreeNode(3);

    cout << "Test Case 1: " << (isSameTree(p1, q1) ? "Same" : "Different") << endl;

    // Test Case 2: Trees are different (structure or values differ)
    TreeNode *p2 = new TreeNode(1);
    p2->left = new TreeNode(2);

    TreeNode *q2 = new TreeNode(1);
    q2->right = new TreeNode(2);

    cout << "Test Case 2: " << (isSameTree(p2, q2) ? "Same" : "Different") << endl;

    // Test Case 3: One tree is empty, the other is not
    TreeNode *p3 = nullptr;
    TreeNode *q3 = new TreeNode(1);

    cout << "Test Case 3: " << (isSameTree(p3, q3) ? "Same" : "Different") << endl;
}

int main()
{
    testCases();
    return 0;
}
