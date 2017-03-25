#include <algorithm>

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

// NOTE(Wuxiang): The Difficulty is how to distinguish 4 cases in switch.
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        if (root->left != nullptr && root->right != nullptr)
        {
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        }
        else if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }
        else if (root->left != nullptr)
        {
            return minDepth(root->left) + 1;
        }
        else
        {
            return minDepth(root->right) + 1;
        }
    }
};