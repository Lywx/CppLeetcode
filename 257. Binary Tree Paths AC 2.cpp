#include <cstddef>
#include <vector>
#include <string>
#include <iostream>

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

#include <algorithm>
#include <deque>
#include <numeric>

using namespace std;

// Recursive solution with a path stack.
class Solution
{
public:
    deque<int>     pathStack;
    vector<string> resultVector;

    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (root == nullptr)
        {
            return resultVector;
        }

        binaryTreePathsInternal(root);

        return resultVector;
    }

    void binaryTreePathsInternal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        pathStack.push_front(root->val);

        if (root->left == nullptr && root->right == nullptr)
        {
            // Note that back of stack is the first elem
            auto result = to_string(pathStack.back());

            // Note that deque iterate from front to back
            //
            //     front -> [0, 1, 2, 3] <- back
            //
            // Note that deque reverse iterate from back to front
            for (auto itr = pathStack.rbegin() + 1; itr != pathStack.rend(); ++itr)
            {
                result.append("->").append(to_string(*itr));
            }

            resultVector.push_back(result);
        }

        // When root is a leave node these won't have effect, so that leave node
        // is pushed, processed and popped.
        binaryTreePathsInternal(root->left);
        binaryTreePathsInternal(root->right);

        pathStack.pop_front();
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

    auto result = Solution().binaryTreePaths(a);
    for(auto r : result)
    {
        cout << r << endl;
    }
}
