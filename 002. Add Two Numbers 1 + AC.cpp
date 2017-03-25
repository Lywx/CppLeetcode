#include <vector>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
using namespace std;

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* l3 = nullptr;
        ListNode* l3r;

        int digitSum        = 0;
        int digitPlus       = 0;
        int digitNormalized = 0;

        while (l1 != nullptr || l2 != nullptr)
        {
            digitPlus = digitSum / 10

            auto exist1 = (l1 != nullptr);
            auto exist2 = (l2 != nullptr);

            auto digit1 = exist1 ? l1->val : 0;
            auto digit2 = exist2 ? l2->val : 0;

            digitSum = digit1 + digit2 + digitPlus;
            digitNormalized = digitSum % 10;

            if (l3 == nullptr)
            {
                l3r = l3 = new ListNode(digitNormalized);
            }
            else
            {
                l3 = l3->next = new ListNode(digitNormalized);
            }

            l1 = exist1 ? l1->next : nullptr;
            l2 = exist2 ? l2->next : nullptr;
        }

        digitPlus = digitSum / 10;
        if (digitPlus != 0)
        {
            l3 = l3->next = new ListNode(digitPlus);
        }

        return l3r;
    }
};