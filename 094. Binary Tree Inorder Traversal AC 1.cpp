#include <vector>
#include <cstddef>

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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<int> result;

    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return result;
        }

        inorderTraversal(root->left);

        result.push_back(root->val);

        inorderTraversal(root->right);

        return result;
    }
};