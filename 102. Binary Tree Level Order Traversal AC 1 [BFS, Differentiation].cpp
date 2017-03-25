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
#include <algorithm>

using namespace std;

// BFS using level detection. The most important part of this algorithm is to make sure 
// that the traversal result is organized as desired. That is done by comparing the current 
// traversal level or depth. 
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

        queue<pair<TreeNode *, int>> taskQueue;
        taskQueue.push(make_pair(root, 1));

        // Initialize depth count
        auto depthLevel = 1;

        // Prepare the first result container
        resultVector.push_back(vector<int>());

        while(!taskQueue.empty())
        {
            auto taskCurrent = taskQueue.front();
            auto *nodeCurrent = taskCurrent.first;
            auto &depthCurrent = taskCurrent.second;

            taskQueue.pop();

            if (depthCurrent == depthLevel)
            {
                resultVector.back().push_back(nodeCurrent->val);
            }
            else
            {
                depthLevel = max(depthLevel, depthCurrent);

                resultVector.push_back(vector<int>());
                resultVector.back().push_back(nodeCurrent->val);
            }

            if (nodeCurrent->left)
            {
                taskQueue.push(make_pair(nodeCurrent->left, depthCurrent + 1));
            }

            if (nodeCurrent->right)
            {
                taskQueue.push(make_pair(nodeCurrent->right, depthCurrent + 1));
            }
        }

        return resultVector;
    }
};