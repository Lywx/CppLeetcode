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

// Non-recursive solution.
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;

        if (root == nullptr)
        {
            return result;
        }

        stack<pair<TreeNode *, int>> taskStack;
        taskStack.push(make_pair(root, 0));

        while (!taskStack.empty())
        {
            auto taskCurrent = taskStack.top();
            auto *nodeCurrent = taskCurrent.first;
            auto &nodeVisitCurrent = taskCurrent.second;

            taskStack.pop();

            if (++nodeVisitCurrent == 1)
            {
                taskStack.push(taskCurrent);

                if (nodeCurrent->left)
                {
                    taskStack.push(make_pair(nodeCurrent->left, 0));
                }
            }
            else
            {
                // Visit this node here
                result.push_back(nodeCurrent->val);

                if (nodeCurrent->right)
                {
                    taskStack.push(make_pair(nodeCurrent->right, 0));
                }
            }
        }

        return result;
    }
};