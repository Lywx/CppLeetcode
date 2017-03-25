#include <cstddef>

struct TreeLinkNode
{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
public:
    TreeLinkNode *connectedFrontier;

    void connect(TreeLinkNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        TreeLinkNode dummy(-1);
        for (TreeLinkNode *curr = root, *prev = &dummy; curr; curr = curr->next)
        {
            if (curr->left != nullptr)
            {
                prev->next = curr->left;
                prev = prev->next;
            }
            if (curr->right != nullptr)
            {
                prev->next = curr->right;
                prev = prev->next;
            }
        }
        connect(dummy.next);
    }

    void connect(TreeLinkNode *root)
    {
        if (!root)
        {
            return;
        }

        root->next = nullptr;

        if (root->left)
        {
            connectedFrontier = root->right;
            root->left->next = root->right;

            connect(root->left);
            connect(root->right);
        }
        else
        {

        }
    }
};