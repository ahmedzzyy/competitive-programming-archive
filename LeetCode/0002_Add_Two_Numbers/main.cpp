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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // Messy but works - my first attempt
        // if (!l1)
        //     return l2;
        // else if (!l2)
        //     return l1;

        // ListNode *newHead = nullptr;
        // ListNode *current = newHead;

        // int carry = 0;
        // ListNode *curr1 = l1;
        // ListNode *curr2 = l2;

        // while (curr1 || curr2)
        // {
        //     int sum = carry;
        //     if (curr1)
        //     {
        //         sum += curr1->val;
        //         curr1 = curr1->next;
        //     }
        //     if (curr2)
        //     {
        //         sum += curr2->val;
        //         curr2 = curr2->next;
        //     }

        //     carry = sum / 10;
        //     sum = sum % 10;
        //     ListNode *newNode = new ListNode(sum);

        //     if (!newHead)
        //     {
        //         newHead = newNode;
        //         current = newHead;
        //     }
        //     else
        //     {
        //         current->next = newNode;
        //         current = newNode;
        //     }
        // }

        // if (carry > 0)
        //     current->next = new ListNode(carry);

        // return newHead;

        // Cleaner version using a dummy head
        ListNode *dummy = new ListNode(0);
        ListNode *current = dummy;

        int carry = 0;
        while (l1 || l2 || carry)
        {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;

            int sum = a + b + carry;

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        ListNode *result = dummy->next;
        delete dummy; // Free the dummy node
        return result;
    }
};