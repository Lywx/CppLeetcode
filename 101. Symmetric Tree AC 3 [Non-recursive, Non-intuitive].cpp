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

#include <stack>

using namespace std;

// This solution is just the same as the "101. Symmetric Tree 2 AC", only made
// based on non-recursive code.
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        stack<TreeNode *> taskStack;
        taskStack.push(root->right);
        taskStack.push(root->left);

        while (!taskStack.empty())
        {
            // NOTE(Wuxiang): Each insertion of 4 node is symmetrically tested.
            // The number represents the push_back order.
            //   2   1
            //   -   -
            //  3 5 6 4
            //    - -   first
            //  -     - next
            // 10 8 7 9
            //    - -   next
            // -      - first

            // NOTE(Wuxiang): In order to understand this solution better, you could
            // consider the question that why this way of traversal guarantee that
            // every node in the tree is tested? Then this leads to recursive proof,
            // which is implemented more obviously by *101. Symmetric Tree 2 AC*.

            // NOTE(Wuxiang): p is not necessarily the left node geometrically.
            // q has the same property with p.
            TreeNode *p = taskStack.top();
            taskStack.pop();

            TreeNode *q = taskStack.top();
            taskStack.pop();

            if (!p && !q)
            {
                continue;
            }

            if (!p || !q)
            {
                return false;
            }

            if (p->val != q->val)
            {
                return false;
            }

            taskStack.push(p->left);
            taskStack.push(q->right);

            taskStack.push(p->right);
            taskStack.push(q->left);
        }

        return true;
    }
};