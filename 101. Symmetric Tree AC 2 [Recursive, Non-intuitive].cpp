#include <cstddef>

/**
    Definition for a binary tree node.
    struct TreeNode
    {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        return isSymmetric(root->left, root->right);
    }

    // Assume the lhs's position is symmetric with rhs'.
    bool isSymmetric(TreeNode *lhs, TreeNode *rhs)
    {
        if (!lhs && !rhs)
        {
            return true;
        }

        if (!lhs || !rhs)
        {
            return false;
        }

        return lhs->val == rhs->val
               && isSymmetric(lhs->left, rhs->right)
               && isSymmetric(lhs->right, rhs->left);
    }
};