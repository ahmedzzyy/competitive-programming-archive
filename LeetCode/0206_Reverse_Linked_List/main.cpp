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
    ListNode *reverseList(ListNode *head)
    {
        // Recursive approach

        // // - Base condition
        // if (!head)
        //     return nullptr;
        // // that is, reach the end

        // ListNode *newHead = head;
        // if (head->next)
        // {
        //     newHead = reverseList(head->next);
        //     // newHead -> originally the last node
        //     // now the head node
        //     head->next->next = head;
        //     // this head is the old one
        //     // head->next -> is current node consideration
        //     // head->next->next changes the order of next links
        // }
        // head->next = nullptr;
        // // currently considered element is
        // // the current last element in the reverse list

        // return newHead;

        // Iterative approach - also the optimal of them both
        ListNode *current = head, *prev = nullptr;

        while (current)
        {
            ListNode *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
};