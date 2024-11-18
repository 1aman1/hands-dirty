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
public:
  ListNode *rotateRight(ListNode *head, int k)
  {
    if (head == nullptr || head->next == nullptr || k == 0)
      return head;

    ListNode *measuringTape = head;
    int length = 1;
    while (measuringTape->next)
    {
      ++length;
      measuringTape = measuringTape->next;
    }

    k %= length;

    if (k == 0) 
      return head;

    ListNode *slowPtr = head;
    ListNode *fastPtr = head;

    while (k > 0){
      fastPtr = fastPtr->next;
      k--;
    }

    while (fastPtr->next != nullptr)
    {
      slowPtr = slowPtr->next;
      fastPtr = fastPtr->next;
    }

    ListNode *newHead = slowPtr->next;
    slowPtr->next = nullptr;
    fastPtr->next = head;

    return newHead;
  }
};