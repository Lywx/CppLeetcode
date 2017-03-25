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
#include <queue>

using namespace std;

// But preorder traversal doesn't work because while traversing the standard preorder
// traversal code will consecutively insert two child node into the stack or queue.
// This behavior causes that the symmetry of stack or queue will not guarantee the same
// symmetric property of the tree.

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        queue<TreeNode *> taskQueue1;
        taskQueue1.push(root);

        queue<TreeNode *> taskQueue2;
        taskQueue2.push(root);

        while (!taskQueue1.empty() || !taskQueue2.empty())
        {
            preorderTraverseStep(taskQueue1, true);
            preorderTraverseStep(taskQueue2, false);

            if (taskQueue1.size() == taskQueue2.size())
            {
                if (taskQueue1.size() != 0 && !equalTraverseQueue(taskQueue1, taskQueue2))
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

    bool equalTraverseQueue(queue<TreeNode *>& taskQueue1, queue<TreeNode *>& taskQueue2)
    {
        if (taskQueue1.front()->val != taskQueue2.front()->val)
        {
            return false;
        }

        return true;
    }

    void preorderTraverseStep(queue<TreeNode *>& taskQueue, bool taskLeft)
    {
        // Support empty step
        if (taskQueue.empty())
        {
            return;
        }

        TreeNode *nodeCurrent = taskQueue.front();
        taskQueue.pop();

        if (taskLeft)
        {
            if (nodeCurrent->left != nullptr)
            {
                taskQueue.push(nodeCurrent->left);
            }
        }
        else
        {
            if (nodeCurrent->right != nullptr)
            {
                taskQueue.push(nodeCurrent->right);
            }
        }

        // This part of code make this solution wrong. If you want to try to
        // improve it, I think you have to move this code to a place that is
        // parallel to the part above this comment so that each step you will
        // only insert one node (and that node will differentiate the symmetry
        // and asymmetry).

        // This would fail the case like:
        //            1
        //        2      2
        //          3      3

        if (taskLeft)
        {
            if (nodeCurrent->right != nullptr)
            {
                taskQueue.push(nodeCurrent->right);
            }
        }
        else
        {
            if (nodeCurrent->left != nullptr)
            {
                taskQueue.push(nodeCurrent->left);
            }
        }
    }
};