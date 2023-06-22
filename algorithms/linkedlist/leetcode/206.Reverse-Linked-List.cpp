class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *prevNode, *currNode, *nextNode;

        currNode = head;
        prevNode = nullptr;
        nextNode = nullptr;
        while (currNode)
        {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }

        return prevNode;
    }
};
