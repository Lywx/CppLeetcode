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

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
        {
            return l2;
        }

        if (l2 == nullptr)
        {
            return l1;
        }

        ListNode *l3;

        ListNode *p1 = l1;
        ListNode *p2 = l2;

        if (p1->val >= p2->val)
        {
            l3 = p2;
            p2 = p2->next;
            l3->next = nullptr;
        }
        else
        {
            l3 = p1;
            p1 = p1->next;
            l3->next = nullptr;
        }

        ListNode *p3 = l3;

        while (p1 != nullptr
                && p2 != nullptr)
        {
            if (p1->val >= p2->val)
            {
                p3->next = p2;
                p2 = p2->next;
                p3 = p3->next;
            }
            else
            {
                p3->next = p1;
                p1 = p1->next;
                p3 = p3->next;
            }
        }

        if (p1 == nullptr)
        {
            while(p2 != nullptr)
            {
                p3->next = p2;
                p2 = p2->next;
                p3 = p3->next;
            }
        }
        else // (p2 == nullptr) 
        {
            while(p1 != nullptr)
            {
                p3->next = p1;
                p1 = p1->next;
                p3 = p3->next;
            }
        }

        return l3;
    }
};