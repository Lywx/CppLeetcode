#include <cstddef>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <vector>

using namespace std;

// Recursive solution with pre-order traversal with index accessing. Notice this solution is 
// not using BFS. It use preorder traversal with arbitrary index access to organize the result.
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

        levelOrderInternal(root, 1, resultVector);

        return resultVector;
    }

    void levelOrderInternal(TreeNode *root, int depth, vector<vector<int>>& resultVector)
    {
        if (root == nullptr)
        {
            return;
        }

        if (depth > int(resultVector.size()))
        {
            resultVector.push_back(vector<int>());
        }

        resultVector[depth - 1].push_back(root->val);

        levelOrderInternal(root->left, depth + 1, resultVector);
        levelOrderInternal(root->right, depth + 1, resultVector);
    }
};