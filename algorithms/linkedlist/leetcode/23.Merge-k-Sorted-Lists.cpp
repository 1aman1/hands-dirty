class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int SIZE = lists.size();

        if (SIZE == 0)
            return nullptr;

        while (SIZE > 1)
        {
            for (int i = 0; i < SIZE / 2; ++i)
            {
                lists[i] = mergeTwoLists(lists[i], lists[(SIZE - 1) - i]);
            }
            SIZE = (SIZE + 1) / 2;
        }

        return lists.front();
    }

private:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr || list2 == nullptr)
            retuwrn list1 != nullptr ? list1 : list2;

        if (list1->val > list2->val)
            swap(list1, list2);

        list1->next = mergeTwoLists(list1->next, list2);

        return list1;
    }
};