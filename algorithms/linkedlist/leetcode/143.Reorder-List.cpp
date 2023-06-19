#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <bitset>
#include <list>

using namespace std;

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
    void reorderList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return;

        ListNode *list1 = head;
        ListNode *list2 = reverse(middleNode(head));
        merge(list1, list2);
    }

private:
    ListNode *middleNode(ListNode *head)
    {
        if (head->next == nullptr)
        {
            return head;
        }

        ListNode *prev = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;

        return slow;
    }

    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next = curr->next;

        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void merge(ListNode *list1, ListNode *list2)
    {
        while (list1 != nullptr)
        {
            ListNode *list1Next = list1->next;
            ListNode *list2Next = list2->next;

            list1->next = list2;
            if (list1Next == nullptr)
            {
                break;
            }
            list2->next = list1Next;

            list1 = list1Next;
            list2 = list2Next;
        }
    }
};

int main()
{
    Solution obj;
    ListNode *list5 = new ListNode(5);
    // ListNode *list4 = new ListNode(4, list5);
    // ListNode *list3 = new ListNode(3, list4);
    // ListNode *list2 = new ListNode(2, list3);
    // ListNode *list1 = new ListNode(1, list2);

    obj.reorderList(list5);

    while (list5)
    {
        cout << list5->val;
        list5 = list5->next;
    }

    return 0;
}
