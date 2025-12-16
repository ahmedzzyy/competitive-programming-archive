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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;

        ListNode *ahead = head;
        int count = 0;
        while (count < n && ahead != nullptr)
        {
            ahead = ahead->next;
            count++;
        }
        if (ahead == nullptr)
        {
            // Remove head
            ListNode *newHead = head->next;
            delete head;
            return newHead;
        }

        while (ahead != nullptr)
        {
            prev = curr;
            curr = curr->next;
            ahead = ahead->next;
        }

        // Remove curr
        prev->next = curr->next;
        delete curr;
        return head;
    }
};