#include <cstddef>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        if (!root)
        {
            return true;

        }

        return balancedDepth(root) >= 0;
    }

    /**
        Returns the height of `root` if `root` is a balanced tree,
        otherwise, returns `-1`.
    */
    int balancedDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int depthLeft  = balancedDepth(root->left);
        int depthRight = balancedDepth(root->right);

        // Pruning
        if (depthLeft < 0
                || depthRight < 0
                || abs(depthLeft - depthRight) > 1)
        {
            return -1;
        }

        return max(depthLeft, depthRight) + 1;
    }
};