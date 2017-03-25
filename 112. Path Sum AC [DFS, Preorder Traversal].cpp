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

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        return preorderFindPathSumMatch(sum, 0, root);
    }

    int comparePathSum(int target, int sum, int val)
    {
        sum = sum + val;

        if (target == sum)
        {
            return 0;
        }
        else if (target > sum)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }

    // NOTE(Wuxiang): Works for the case there is negative numbers.
    bool preorderFindPathSumMatch(int target, int sum, TreeNode *root)
    {
        if (root != nullptr)
        {
            if (isLeaf(root))
            {
                return comparePathSum(target, sum, root->val) == 0;
            }
            else
            {
                return preorderFindPathSumMatch(target, sum + root->val, root->left)
                       || preorderFindPathSumMatch(target, sum + root->val, root->right);
            }
        }

        // NOTE(Wuxiang): The contract we have here is that we won't usually allow to pass
        // null normally into this method. If we did, then it is the case we haven't
        // find the match of the sum in parent node. In this case, child is null, the
        // result should be false because there is no way to match the sum from this point.
        return false;
    }

    // NOTE(Wuxiang): Works for the case there is no negative number.
    // bool preorderFindPathSumMatch(int target, int sum, TreeNode *root)
    // {
    //     if (root != nullptr)
    //     {
    //         auto comparison = comparePathSum(target, sum, root->val);
    //         if (comparison == 0)
    //         {
    //             if (isLeaf(root))
    //             {
    //                 return true;
    //             }
    //             else
    //             {
    //                 return false;
    //             }
    //         }
    //         else if (comparison > 0)
    //         {
    //             if (preorderFindPathSumMatch(target, sum + root->val, root->left))
    //             {
    //                 return true;
    //             }

    //             if (preorderFindPathSumMatch(target, sum + root->val, root->right))
    //             {
    //                 return true;
    //             }
    //         }
    //         else
    //         {
    //             return false;
    //         }
    //     }

    //     // NOTE(Wuxiang): The contract we have here is that we won't usually allow to pass
    //     // null normally into this method. If we did, then it is the case we haven't
    //     // find the match of the sum in parent node. In this case, child is null, the
    //     // result should be false because there is no way to match the sum from this point.
    //     return false;
    // }

    bool isLeaf(TreeNode *root)
    {
        return root->left == nullptr && root->right == nullptr;
    }
};