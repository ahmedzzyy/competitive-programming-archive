// Definition for singly-linked list.
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *headOfPreviousGroup = dummy;

        while (true)
        {
            ListNode *kthNode = headOfPreviousGroup;
            for (int i = 0; i < k; ++i)
            {
                kthNode = kthNode->next;
                if (kthNode == nullptr)
                {
                    return dummy->next;
                }
            }

            ListNode *groupPrev = headOfPreviousGroup;
            ListNode *groupCurr = headOfPreviousGroup->next;
            ListNode *groupNext = kthNode->next;

            for (int i = 0; i < k; ++i)
            {
                ListNode *tempNext = groupCurr->next;
                groupCurr->next = groupPrev;
                groupPrev = groupCurr;
                groupCurr = tempNext;
            }

            ListNode *headOfCurrentGroup = headOfPreviousGroup->next;
            headOfCurrentGroup->next = groupNext;
            headOfPreviousGroup->next = kthNode;

            headOfPreviousGroup = headOfCurrentGroup;
        }

        return dummy->next;
    }
};