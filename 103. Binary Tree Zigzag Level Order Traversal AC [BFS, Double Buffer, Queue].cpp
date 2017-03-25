#include <cstddef>
#include <vector>

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

#include <queue>
using namespace std;

class Solution
{
public:

    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> resultVector;

        if (root == nullptr)
        {
            return resultVector;
        }

        queue<TreeNode *> taskCurrentQueue, taskNextQueue;
        taskCurrentQueue.push(root);

        auto taskLeftToRight = true;

        while(!taskCurrentQueue.empty())
        {
            resultVector.push_back(vector<int>());

            while(!taskCurrentQueue.empty())
            {
                auto taskCurrent = taskCurrentQueue.front();
                taskCurrentQueue.pop();

                resultVector.back().push_back(taskCurrent->val);

                if (taskCurrent->left)
                {
                    taskNextQueue.push(taskCurrent->left);
                }

                if (taskCurrent->right)
                {
                    taskNextQueue.push(taskCurrent->right);
                }
            }

            if (!taskLeftToRight)
            {
                reverse(resultVector.back().begin(), resultVector.back().end());
            }

            swap(taskCurrentQueue, taskNextQueue);
            taskLeftToRight = !taskLeftToRight;
        }

        return resultVector;
    }
};