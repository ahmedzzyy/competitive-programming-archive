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
    void reorderList(ListNode *head)
    {
        // My approach
        // One node for the start and one for the end
        // Add the end node after the start node
        // Move the end to its prev and the start to its next
        // Problem: can't get end's prev in singly linked list

        // Better approach
        // Find the middle node
        // Reverse the second half
        // Merge the two halves

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = nullptr;
        ListNode *curr = slow->next;
        while (curr != nullptr)
        {
            ListNode *nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        slow->next = nullptr;

        // prev is the head of the reversed second half
        ListNode *first = head;
        ListNode *second = prev;
        while (second != nullptr)
        {
            ListNode *tmp1 = first->next;
            ListNode *tmp2 = second->next;

            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }
};