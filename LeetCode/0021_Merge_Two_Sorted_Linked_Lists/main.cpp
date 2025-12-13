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
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        ListNode *currentInMerged = nullptr, *head = nullptr;

        ListNode *currentInList1 = list1;
        ListNode *currentInList2 = list2;

        while (currentInList1 && currentInList2)
        {
            if (currentInList1->val > currentInList2->val)
            {
                if (!currentInMerged)
                {
                    currentInMerged = currentInList2;
                    head = currentInMerged;
                }
                else
                {
                    currentInMerged->next = currentInList2;
                    currentInMerged = currentInMerged->next;
                }

                currentInList2 = currentInList2->next;
            }
            else
            {
                if (!currentInMerged)
                {
                    currentInMerged = currentInList1;
                    head = currentInMerged;
                }
                else
                {
                    currentInMerged->next = currentInList1;
                    currentInMerged = currentInMerged->next;
                }

                currentInList1 = currentInList1->next;
            }
        }

        if (currentInList1)
        {
            currentInMerged->next = currentInList1;
        }
        else if (currentInList2)
        {
            currentInMerged->next = currentInList2;
        }

        return head;
    }
};