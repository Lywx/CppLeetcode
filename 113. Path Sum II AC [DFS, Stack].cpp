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
#include <vector>
#include <deque>

struct TreeNode
{

    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

class Solution

{
public:
    vector<vector<int>> mPaths;

    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        deque<int> pathStack;

        pathSumInternal(root, sum, pathStack);

        return mPaths;
    }

    void pathSumInternal(TreeNode *root, int sum, deque<int>& pathStack)
    {
        if (root == nullptr)
        {
            return;
        }

        pathStack.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr)
        {
            if (root->val == sum)
            {
                addPath(pathStack);
            }
        }

        pathSumInternal(root->left, sum - root->val, pathStack);
        pathSumInternal(root->right, sum - root->val, pathStack);

        pathStack.pop_back();
    }

    void addPath(deque<int>& nodePath)
    {
        static vector<int> sPath;

        sPath.clear();

        for (auto iter = nodePath.begin(); iter != nodePath.end(); ++iter)
        {
            sPath.push_back(*iter);
        }

        mPaths.push_back(sPath);
    }
};
