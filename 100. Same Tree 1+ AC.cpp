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

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {

    }
};

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }

        // Result of true table
        if ((p == nullptr) || (q == nullptr))
        {
            return false;
        }
        else // (p != nullptr && q != nullptr)
        {
            return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};