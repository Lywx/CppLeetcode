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

#include <set>

using namespace std;

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        set<int> known;

        if (head == nullptr)
        {
            return nullptr;
        }

        ListNode *previous = head;
        known.insert(previous->val);

        ListNode *current = head->next;

        while (current != nullptr)
        {
            if (known.find(current->val) != known.end())
            {
                previous->next = current->next;
                current->next = nullptr;
                current = previous->next;
            }
            else
            {
                known.insert(current->val);

                previous = current;
                current = current->next;
            }
        }

        return head;
    }
};