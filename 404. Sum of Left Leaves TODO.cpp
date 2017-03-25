#include <cstddef>
#include <stack>

using namespace std;

/**
    Definition for a binary tree node.
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        if (root->left != nullptr
                && root->left->left == nullptr
                && root->left->right == nullptr)
        {
            return root->val + root->left->val + sumOfLeftLeaves(root->right);
        }
        else if (root->left != nullptr
                 && root->left->left != nullptr
                 && root->left->right == nullptr)
        {
            return root->val + root->left->val;
        }
        else if (root->left != nullptr
                 && root->left->left != nullptr
                 && root->left->right != nullptr)
        {
            return root->val + root->left->val;
        }
        else
        {
            return 0;
        }
    }
};