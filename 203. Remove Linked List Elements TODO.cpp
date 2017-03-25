#include <cstddef>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        auto current = head;
        while(current != nullptr)
        {
            if (current->val == val)
            {
                auto next = current->next;
                if (next)
                {
                    current->val = next->val;
                    current->next = next->next;

                    delete next;
                }
                else
                {
                    delete current;

                    return head;
                }
            }

            current = current->next;
        }

        return head;
    }
};