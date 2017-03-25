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
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {

    }
};

#include <stack>
#include <queue>

using namespace std;

class Solution
{
public:

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        queue<TreeNode *> queue;
        queue.push(p);
        queue.push(q);

        while(!queue.empty())
        {
            TreeNode *pp = queue.front();
            queue.pop();

            TreeNode *qq = queue.front();
            queue.pop();

            if (!pp && !qq)
            {
                continue;
            }

            if (!pp || !qq)
            {
                return false;
            }

            if (pp->val != qq->val)
            {
                return false;
            }

            queue.push(pp->left);
            queue.push(qq->left);

            queue.push(pp->right);
            queue.push(qq->right);
        }

        return true;
    }
};