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
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r)
    {
    }
};

// NOTE(Wuxiang): It is important that you would be able to reduce the problem
// into simple cases -- to divide and conquer. It is also important that you
// would be able to analyze in term of switch statement.

// NOTE(Wuxiang): It is also important that you would realize how the recursive
// division is spawn and how the process stack is used.
class Solution
{
public:
    int target;

    int pathSum(TreeNode *root, int sum)
    {
        target = sum;

        return pathSumInternal(root, sum, true);
    }

    // @param reset -- Restart the sequence counting.
    int pathSumInternal(TreeNode *root, int sum, bool reset)
    {
        // NOTE(Wuxiang): This is the termination condition. Impossible to
        // extend if the sum is already matched.
        if (root == nullptr)
        {
            return 0;
        }

        // NOTE(Wuxiang): Case 1, count as part of the sum.
        auto matchPath = 0;

        // WARN(Wuxiang): Parenthesis is necessary.
        matchPath += (root->val == sum ? 1 : 0)
                     + pathSumInternal(root->left, sum - root->val, false)
                     + pathSumInternal(root->right, sum - root->val, false);

        // NOTE(Wuxiang): Make sure that sum reset only spawn by the root of the
        // sequence.
        //
        // WARN(Wuxiang): if (sum == target) -- This cannot guarantee the spawner
        // is the root node of a path. It is possible for sequence "9, -9, 9" to
        // mimic the target value.
        if (reset)
        {
            // NOTE(Wuxiang): Case 2, not count as part of the sum -- restart sequence.
            matchPath += pathSumInternal(root->left, target, true)
                         + pathSumInternal(root->right, target, true);
        }

        return matchPath;
    }
};