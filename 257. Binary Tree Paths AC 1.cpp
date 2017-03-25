#include <cstddef>
#include <vector>
#include <string>

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

// Non-recursive solution with BFS.
class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> resultVector;

        if (root == nullptr)
        {
            return resultVector;
        }

        queue<pair<TreeNode *, string>> taskQueue;
        taskQueue.push(make_pair(root, to_string(root->val)));

        while(!taskQueue.empty())
        {
            auto taskCurrent = taskQueue.front();
            auto *nodeCurrent = taskCurrent.first;
            auto &stringCurrent = taskCurrent.second;
            taskQueue.pop();

            // Process path string in task, the insertion of new node is already
            // done in the push statements in below
            if (nodeCurrent->left == nullptr && nodeCurrent->right == nullptr)
            {
                resultVector.push_back(stringCurrent);
            }

            if (nodeCurrent->left)
            {
                taskQueue.push(make_pair(nodeCurrent->left, stringCurrent.append("->").append(to_string(nodeCurrent->left->val))));
            }

            if (nodeCurrent->right)
            {
                taskQueue.push(make_pair(nodeCurrent->right, stringCurrent.append("->").append(to_string(nodeCurrent->right->val))));
            }
        }

        return resultVector;
    }
};

void main()
{
    auto *a = new TreeNode(1);
    auto *b = new TreeNode(2);
    auto *c = new TreeNode(3);
    auto *d = new TreeNode(4);

    a->left = b;
    a->right = c;
    b->left = d;

    Solution().binaryTreePaths(a);
}
