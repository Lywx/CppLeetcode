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

#include <vector>
#include <stack>

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;

        if (root == nullptr)
        {
            return result;
        }

        stack<TreeNode *> taskStack;
        taskStack.push(root);

        while(!taskStack.empty())
        {
            auto *current = taskStack.top();
            taskStack.pop();

            result.push_back(current->val);

            if (current->right != nullptr)
            {
                taskStack.push(current->right);
            }

            if (current->left != nullptr)
            {
                taskStack.push(current->left);
            }
        }

        return result;
    }
};