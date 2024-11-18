class Solution
{
public:
  ListNode *deleteDuplicates(ListNode *head)
  {
    ListNode *dummy = new ListNode(0, head);
    ListNode *prev = dummy;

    while (head != nullptr)
    {
      while (head->next && head->val == head->next->val)
        head = head->next;

      if (prev->next == head)
        prev = prev->next;
      else
      {

        ListNode *duplicateRange = prev->next;

        prev->next = head->next;

        while (duplicateRange->next != head->next)
        {
          ListNode *deleter = duplicateRange;
          duplicateRange = duplicateRange->next;
          delete deleter;
        }
      }
      head = head->next;
    }

    ListNode *newHead = dummy->next;
    delete dummy;

    return newHead;
  }
};