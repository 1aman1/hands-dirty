#include <iostream>

using namespace std;
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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr || list2 == nullptr)
            return list1 ? list1 : list2;

        ListNode *newHead = nullptr;
        ListNode *tail = nullptr;

        if (list1->val < list2->val)
        {
            newHead = list1;
            list1 = list1->next;
        }
        else
        {
            newHead = list2;
            list2 = list2->next;
        }

        tail = newHead;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1)
            tail->next = list1;
        if (list2)
            tail->next = list2;

        return newHead;
    }
};

int main()
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // ListNode *list2 = nullptr;
    ListNode *list2 = new ListNode(1);
    // list2->next = new ListNode(3);
    // list2->next->next = new ListNode(4);
    // list2->next->next->next = new ListNode(5);

    Solution obj;
    ListNode *sorted = obj.mergeTwoLists(list1, list2);

    while (sorted)
    {
        cout << sorted->val << " ";
        sorted = sorted->next;
    }

    return 0;
}