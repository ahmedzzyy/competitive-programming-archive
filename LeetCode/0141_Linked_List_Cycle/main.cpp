struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        // Floyd's Cycle Finding algorithm
        // or Tortoise and Hare algorithm
        if (head == nullptr)
            return false;

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != nullptr && fast->next != nullptr)
        {
            if (slow == fast)
                return true;

            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }
};