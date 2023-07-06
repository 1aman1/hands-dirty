class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *list1, ListNode *list2)
    {
        ListNode *newList = new ListNode();
        ListNode *currNode = newList;
        int carry = 0;

        while (list1 != nullptr || list2 != nullptr)
        {
            int val1 = (list1 != nullptr) ? list1->val : 0;
            int val2 = (list2 != nullptr) ? list2->val : 0;

            int sum = val1 + val2 + carry;
            carry = sum / 10;

            currNode->next = new ListNode(sum % 10);
            currNode = currNode->next;

            if (list1 != nullptr)
            {
                list1 = list1->next;
            }
            if (list2 != nullptr)
            {
                list2 = list2->next;
            }
        }
        if (carry == 1)
            currNode->next = new ListNode(1);

        return newList->next;
    }
};