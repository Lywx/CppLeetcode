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
    vector<int> postorderTraversal(TreeNode *root)
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
            auto *nodedCurrent = taskCurrent.first;
            auto &nodeVisitCurrent = taskCurrent.second;

            taskStack.pop();

            if (++nodeVisitCurrent == 1)
            {
                taskStack.push(taskCurrent);

                if (nodedCurrent->left)
                {
                    taskStack.push(make_pair(nodedCurrent->left, 0));
                }
            }
            else if (nodeVisitCurrent == 2)
            {
                taskStack.push(taskCurrent);

                if (nodedCurrent->right)
                {
                    taskStack.push(make_pair(nodedCurrent->right, 0));
                }
            }
            else
            {
                result.push_back(nodedCurrent->val);
            }
        }

        return result;
    }
};