/**
    Definition for a binary tree node.
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
*/

#include <cstddef>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive solution with the post-order right-first traversal.
class Solution
{
public:
    TreeNode *current;

    void flatten(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        flatten(root->right);
        flatten(root->left);

        if (current)
        {
            if (root->left == current)
            {
                root->left = nullptr;
            }

            root->right = current;
        }

        current = root;
    }
};