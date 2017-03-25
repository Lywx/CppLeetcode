#include <cstddef>
#include <cassert>

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

// NOTE(Wuxiang): You better start considering this problem from different edge
// cases. This way of thinking actually will help you debug from the start.

// NOTE(Wuxiang): You should use step by step diagram to understand consequence
// of every line of code you write.
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        else if (head->next == nullptr)
        {
            return head;
        }

        // Assume at least 2 node existing

        auto *a = head;
        auto *b = head->next;
        assert(b != nullptr);

        // Only executed on first node
        a->next = nullptr;

        ListNode *c;
        do
        {
            c = b->next;

            b->next = a;
            a = b;
            b = c;
        }

        // Has to distinguish the 2 node and (3 or more)
        // When 2 node, c == nullptr
        // When 3 node, c != nullptr
        while (c != nullptr);

        return a;
    }
};