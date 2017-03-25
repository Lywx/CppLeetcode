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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <stack>

using namespace std;

// Non-recursive solution with the post-order right-first traversal.
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        stack<pair<TreeNode *, int>> taskStack;
        TreeNode *nodeToMove = nullptr;

        taskStack.push(make_pair(root, 0));
        while (!taskStack.empty())
        {
            auto taskCurrent = taskStack.top();
            auto *nodeCurrent = taskCurrent.first;

            taskStack.pop();
            if (++taskCurrent.second == 3)
            {
                if (nodeCurrent->left == nodeToMove)
                {
                    nodeCurrent->left = nullptr;
                }

                nodeCurrent->right = nodeToMove;

                nodeToMove = nodeCurrent;

                continue;
            }

            taskStack.push(taskCurrent);

            if (taskCurrent.second == 1)
            {
                if (nodeCurrent->right)
                {
                    taskStack.push(make_pair(nodeCurrent->right, 0));
                }
            }
            else
            {
                if (nodeCurrent->left)
                {
                    taskStack.push(make_pair(nodeCurrent->left, 0));
                }
            }
        }
    }
};