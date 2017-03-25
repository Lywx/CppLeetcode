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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<int> result;

    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return result;
        }
        else
        {
            result.push_back(root->val);
        }

        preorderTraversal(root->left);
        preorderTraversal(root->right);

        return result;
    }
};