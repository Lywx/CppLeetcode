#include <cstddef>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <vector>
#include <queue>

using namespace std;

// BFS using double buffer. This method is using two buffer to separate different level of nodes. 
// After finishing visiting each level of nodes, you would swap the buffer to visit the next.
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        auto resultVector = vector<vector<int>>();

        if (root == nullptr)
        {
            return resultVector;
        }

        queue<pair<TreeNode *, int>> taskCurrentQueue, taskNextQueue;
        taskCurrentQueue.push(make_pair(root, 1));

        while(!taskCurrentQueue.empty())
        {
            // Initialize traversal result for this level.
            resultVector.push_back(vector<int>());

            // Complete traversing current level.
            while (!taskCurrentQueue.empty())
            {
                auto taskCurrent = taskCurrentQueue.front();
                auto *nodeCurrent = taskCurrent.first;
                auto &depthCurrent = taskCurrent.second;

                taskCurrentQueue.pop();

                // Visit the node.
                resultVector.back().push_back(nodeCurrent->val);

                if (nodeCurrent->left)
                {
                    taskNextQueue.push(make_pair(nodeCurrent->left, depthCurrent + 1));
                }

                if (nodeCurrent->right)
                {
                    taskNextQueue.push(make_pair(nodeCurrent->right, depthCurrent + 1));
                }
            }

            swap(taskCurrentQueue, taskNextQueue);
        }

        return resultVector;
    }
};