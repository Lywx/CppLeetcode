#include <cstddef>
#include <vector>

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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    typedef unsigned int TreeIndex;

    TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        TreeIndex preorderIndex = 0;
        TreeIndex inorderIndexA = 0;
        TreeIndex inorderIndexB = 0;

        TreeNode *root = nullptr;

        while (preorderIndex < preorder.size())
        {
            auto rootVal = preorder[preorderIndex];
            while(rootVal != inorder[inorderIndexB])
            {
                ++inorderIndexB;
            }

            buildTreeInternal(preorder, inorder, preorderIndex, inorderIndexA, inorderIndexB, root);
        }

        return root;
    }

    void buildTreeInternal(vector<int>& preorder, vector<int>& inorder, TreeIndex& preorderIndex, TreeIndex inorderIndexA, TreeIndex inorderIndexB, TreeNode *&root)
    {
        root = new TreeNode(inorder[inorderIndexB]);
        ++preorderIndex;

        auto rootVal = preorder[preorderIndex];

        inorderIndexB = inorderIndexA;
        while (rootVal != inorder[inorderIndexB])
        {
            ++inorderIndexB;
        }

        if () {
            buildTreeInternal(preorder, inorder, preorderIndex, inorderIndexA, inorderIndexB, root->left);
        }

        buildTreeInternal(preorder, inorder, preorderIndex, inorderIndexA, inorderIndexB, root->right);
    }
};