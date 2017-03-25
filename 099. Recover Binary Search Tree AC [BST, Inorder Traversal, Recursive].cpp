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

#include <vector>

using namespace std;

class Solution
{
public:
    vector<pair<int, TreeNode *>> inorderTraversal;
    vector<int>                   inconsistentIndex;

    void recoverTree(TreeNode *root)
    {
        // Build the array in ascending order.
        inorderTravere(root);

        // Linear search for inconsistent ordering.
        for (int i = 0; i < inorderTraversal.size() - 1; ++i)
        {
            if (inorderTraversal[i].first - inorderTraversal[i + 1].first > 0)
            {
                inconsistentIndex.push_back(i);
            }
        }

        int       index1;
        int       index2;
        TreeNode *node1;
        TreeNode *node2;

        // Case discussion for finding index of swapped node (easy to notice
        // this relationship using special cases).
        if (inconsistentIndex.size() == 1)
        {
            index1 = inconsistentIndex[0];
            index2 = index1 + 1;
        }
        else // if (inconsistentIndex.size() == 2)
        {
            index1 = inconsistentIndex[0];
            index2 = inconsistentIndex[1] + 1;
        }

        node1 = inorderTraversal[index1].second;
        node2 = inorderTraversal[index2].second;

        // Swap value.
        swap(node1->val, node2->val);
    }

    void inorderTravere(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        inorderTravere(root->left);
        inorderTraversal.push_back(make_pair(root->val, root));
        inorderTravere(root->right);
    }
};
