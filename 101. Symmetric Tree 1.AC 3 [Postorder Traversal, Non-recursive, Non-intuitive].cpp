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
#include <iostream>

using namespace std;

// Convert the task of comparing tree into comparing traversal stack. You don't
// have to use the postorder traversal.
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        stack<pair<TreeNode *, int>> taskStack1;
        stack<TreeNode *> taskUniqueStack1;
        taskStack1.push(make_pair(root, 0));

        stack<pair<TreeNode *, int>> taskStack2;
        stack<TreeNode *> taskUniqueStack2;
        taskStack2.push(make_pair(root, 0));

        while (!taskStack1.empty() || !taskStack2.empty())
        {
            postorderTraverseStep(taskStack1, taskUniqueStack1, true);
            postorderTraverseStep(taskStack2, taskUniqueStack2, false);

            if (taskUniqueStack1.size() == taskUniqueStack2.size())
            {
                if (taskUniqueStack1.size() != 0 && !equalTraverseStack(taskUniqueStack1, taskUniqueStack2))
                {
                    return false;
                }

                // Possibly symmetric
            }
            else
            {
                return false;
            }
        }

        return true;
    }

    bool equalTraverseStack(stack<TreeNode *>& taskStack1, stack<TreeNode *>& taskStack2)
    {
        if (taskStack1.top()->val != taskStack2.top()->val)
        {
            return false;
        }

        return true;
    }

    void postorderTraverseStep(stack<pair<TreeNode *, int>>& taskStack, stack<TreeNode *>& taskUniqueStack, bool taskLeft)
    {
        // Support empty step
        if (taskStack.empty())
        {
            return;
        }

        pair<TreeNode *, int> taskCurrent = taskStack.top();
        taskStack.pop();

        TreeNode *nodeCurrent = taskCurrent.first;
        int &nodeVisitCurrent = taskCurrent.second;

        if (++nodeVisitCurrent == 1)
        {
            taskStack.push(taskCurrent);

            if (taskLeft)
            {
                if (nodeCurrent->left != nullptr)
                {
                    taskStack.push(make_pair(nodeCurrent->left, 0));
                    taskUniqueStack.push(nodeCurrent->left);
                }
            }
            else
            {
                if (nodeCurrent->right != nullptr)
                {
                    taskStack.push(make_pair(nodeCurrent->right, 0));
                    taskUniqueStack.push(nodeCurrent->right);
                }
            }
        }
        else if (nodeVisitCurrent == 2)
        {
            taskStack.push(taskCurrent);

            if (taskLeft)
            {
                if (nodeCurrent->right != nullptr)
                {
                    taskStack.push(make_pair(nodeCurrent->right, 0));
                    taskUniqueStack.push(nodeCurrent->right);
                }
            }
            else
            {
                if (nodeCurrent->left != nullptr)
                {
                    taskStack.push(make_pair(nodeCurrent->left, 0));
                    taskUniqueStack.push(nodeCurrent->left);
                }
            }
        }
        else
        {
            if (taskLeft)
            {
                taskUniqueStack.push(nodeCurrent);
            }
            else
            {
                taskUniqueStack.push(nodeCurrent);
            }
        }
    }
};