
// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;

        // // Traverse the original list and create new nodes
        // Node *curr = head;
        // Node *newHead = nullptr;
        // Node *newCurr = nullptr;
        // while (curr)
        // {
        //     Node *newNode = new Node(curr->val);
        //     if (!newHead)
        //     {
        //         newHead = newNode;
        //         newCurr = newHead;
        //     }
        //     else
        //     {
        //         newCurr->next = newNode;
        //         newCurr = newCurr->next;
        //     }
        //     curr = curr->next;
        // }

        // // Set the random pointers for the new nodes
        // curr = head;
        // newCurr = newHead;
        // while (curr)
        // {
        //     if (curr->random)
        //     {
        //         Node *temp = head;
        //         Node *newTemp = newHead;
        //         while (temp != curr->random)
        //         {
        //             temp = temp->next;
        //             newTemp = newTemp->next;
        //         }
        //         newCurr->random = newTemp;
        //     }
        //     curr = curr->next;
        //     newCurr = newCurr->next;
        // }

        // return newHead;

        // Interleaving method
        // Phase 1: Create new nodes and
        // interleave them with original nodes
        Node *current = head;
        while (current)
        {
            Node *newNode = new Node(current->val);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;
        }

        // Phase 2: Set random pointers for new nodes
        current = head;
        while (current)
        {
            if (current->random)
            {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        // Phase 3: Separate the two lists
        current = head;
        Node *newHead = head->next;
        Node *newCurrent = newHead;
        while (current)
        {
            current->next = current->next->next;
            if (newCurrent->next)
            {
                newCurrent->next = newCurrent->next->next;
                newCurrent = newCurrent->next;
            }
            current = current->next;
        }

        return newHead;
    }
};