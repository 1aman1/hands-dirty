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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;
        ListNode* blueFlag = nullptr;
        ListNode* greenFlag = nullptr;

        while( k > 1){
            fastPtr = fastPtr->next;
            k--;
        }

        blueFlag = fastPtr;

        while(fastPtr->next != nullptr){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }

        greenFlag = slowPtr;

        swap(blueFlag->val, greenFlag->val);

        return head;
    }
};