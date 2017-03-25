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

// NOTE(Wuxiang): Think before you code. This problem has recursive relation:
// maxDepth(parent) = max(maxDepth(left), maxDepth(right)) + 1

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};