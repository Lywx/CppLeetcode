#include <cstddef>

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

#include <vector>
#include <queue>

using namespace std;

// BFS with double buffer mostly identical to *102. Binary Tree Level Order Traversal 2 AC.cpp* with addition of line 70
class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        auto resultVector = vector<vector<int>>();

        if (root == nullptr)
        {
            return resultVector;
        }

        queue<pair<TreeNode *, int>> taskCurrentQueue, taskNextQueue;
        taskCurrentQueue.push(make_pair(root, 1));

        while (!taskCurrentQueue.empty())
        {
            resultVector.push_back(vector<int>());

            while (!taskCurrentQueue.empty())
            {
                auto taskCurrent = taskCurrentQueue.front();
                auto *nodeCurrent = taskCurrent.first;
                auto &depthCurrent = taskCurrent.second;

                taskCurrentQueue.pop();

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

        reverse(resultVector.begin(), resultVector.end());
        return resultVector;
    }
};

void main()
{
    auto *a = new TreeNode(3);
    auto *b = new TreeNode(9);
    auto *c = new TreeNode(20);
    a->left = b;
    a->right = c;

    auto *d = new TreeNode(1);
    auto *e = new TreeNode(1);
    c->left = d;
    c->right = e;

    Solution().levelOrderBottom(a);
}
