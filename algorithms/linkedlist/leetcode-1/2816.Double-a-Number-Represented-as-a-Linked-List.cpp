/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
    bool cache = false;

public:
    ListNode *doubleIt(ListNode *head)
    {
        mux(head);

        if (cache)
        {
            ListNode *newHead = new ListNode(1);
            newHead->next = head;
            return newHead;
        }
        else
        {
            return head;
        }
    }

    ListNode *mux(ListNode *head)
    {
        if (head->next != NULL)
        {
            mux(head->next);
        }

        int x2 = head->val * 2;
        if (cache)
        {
            ++x2;
        }
        head->val = x2 % 10;
        x2 > 9 ? cache = true : cache = false;
        return head;
        /*
        2x
        if cache add 1
        prep cache by >9
        save in head->val %10
        */
    }
};