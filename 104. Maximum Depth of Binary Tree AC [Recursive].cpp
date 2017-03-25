/**
    Definition for a binary tree node.
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
*/

#include <algorithm>
#include <cstddef>
#include <cmath>

using namespace std;

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        return travese(root, 0);
    }

    int travese(TreeNode *node, int height)
    {
        if (node == nullptr)
        {
            return height;
        }

        int left  = height + 1;
        int right = height + 1;

        if (node->left != nullptr)
        {
            left = travese(node->left, height + 1);
        }

        if (node->right != nullptr)
        {
            right = travese(node->right, height + 1);
        }

        return max(left, right);
    }
};