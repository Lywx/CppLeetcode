#include <cstddef>

/**
    Definition for singly-linked list.
    struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
    };
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#include <vector>

using namespace std;

// Useful when the input set is non-negative, but not this problem where the input
// set is not non-negative.
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        const int max = 100;
        vector<bool> known(max, false);

        if (head == nullptr)
        {
            return nullptr;
        }

        ListNode *previous = head;
        known[previous->val] = true;

        ListNode *current = head->next;

        while (current != nullptr)
        {
            if (known[current->val])
            {
                previous->next = current->next;
                current->next = nullptr;
                current = previous->next;
            }
            else
            {
                known[current->val] = true;

                previous = current;
                current = current->next;
            }
        }

        return head;
    }
};