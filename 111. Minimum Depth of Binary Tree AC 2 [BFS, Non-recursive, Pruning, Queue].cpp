#include <algorithm>

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

#include <queue>

// Non-recursive solution with pruning. This is impossible to prune without
// knowing already computed tree height. Recursive solution doesn't work well with
// pruning.
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int result = INT_MAX;

        queue<pair<TreeNode *, int>> taskQueue;
        taskQueue.push(make_pair(root, 1));

        // BFS in BST
        while(!taskQueue.empty())
        {
            auto taskCurrent = taskQueue.front();
            auto *nodeCurrent = taskCurrent.first;
            auto depthCurrent = taskCurrent.second;

            taskQueue.pop();

            if (nodeCurrent->left == nullptr && nodeCurrent->right == nullptr)
            {
                result = min(result, depthCurrent);
                continue;
            }

            // Pruning when current depth of given branch is already greater or
            // equal to existing tree height
            if (nodeCurrent->left != nullptr && !(depthCurrent >= result))
            {
                taskQueue.push(make_pair(nodeCurrent->left, depthCurrent + 1));
            }

            // Pruning when current depth of given branch is already greater or
            // equal to existing tree height
            if (nodeCurrent->right != nullptr && !(depthCurrent >= result))
            {
                taskQueue.push(make_pair(nodeCurrent->right, depthCurrent + 1));
            }
        }

        return result;
    }
};