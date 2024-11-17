class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* slowPtr = dummy;
        ListNode* fastPtr = dummy;

        while (k > 0) {
            fastPtr = fastPtr->next;
            k--;
        }

        while (fastPtr->next != nullptr) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }

        ListNode* nodeToRemove = slowPtr->next;
        slowPtr->next = nodeToRemove->next;
        delete nodeToRemove;

        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};
