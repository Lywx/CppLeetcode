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

using namespace std;

// Convert the task of comparing tree into comparing traversal stack. You don't
// have to use the inorder traversal. The reason that inorder traversal work here,
// is at every "step" of traversal, the task stack always changed by one node. The
// front node could represents the sequence of traversal.
//
// In fact, I think postorder traversal will work also.
//
// But preorder traversal doesn't work because while traversing the standard preorder
// traversal code will consecutively insert two child node into the stack or queue.
// This behavior causes that the symmetry of stack or queue will not guarantee the same
// symmetric property of the tree. See (1.2 WA)

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
        taskStack1.push(make_pair(root, 0));

        stack<pair<TreeNode *, int>> taskStack2;
        taskStack2.push(make_pair(root, 0));

        while (!taskStack1.empty() || !taskStack2.empty())
        {
            inorderTraverseStep(taskStack1, true);
            inorderTraverseStep(taskStack2, false);

            if (taskStack1.size() == taskStack2.size())
            {
                if (taskStack1.size() != 0 && !equalTraverseStack(taskStack1, taskStack2))
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

    bool equalTraverseStack(stack<pair<TreeNode *, int>>& taskStack1, stack<pair<TreeNode *, int>>& taskStack2)
    {
        if (taskStack1.top().first->val != taskStack2.top().first->val)
        {
            return false;
        }

        return true;
    }

    void inorderTraverseStep(stack<pair<TreeNode *, int>>& taskStack, bool taskLeft)
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
                }
            }
            else
            {
                if (nodeCurrent->right != nullptr)
                {
                    taskStack.push(make_pair(nodeCurrent->right, 0));
                }
            }
        }
        else
        {
            if (taskLeft)
            {
                if (nodeCurrent->right != nullptr)
                {
                    taskStack.push(make_pair(nodeCurrent->right, 0));
                }
            }
            else
            {
                if (nodeCurrent->left != nullptr)
                {
                    taskStack.push(make_pair(nodeCurrent->left, 0));
                }
            }
        }
    }
};