#include <vector>

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // Approach:
        // Think of the array as a linked list
        // index <-> value of linked list node
        // values are from 1 to n
        // n + 1 elements

        // Phase 1: Finding the intersection point
        // of fast and slow pointers
        // which give us a point inside the cycle
        int slow = 0, fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            // We wont worry about going out of bounds
            // because of the problem constraints
        } while (slow != fast);

        // Phase 2: Finding the entrance to the cycle
        int anotherSlow = 0;
        while (anotherSlow != slow)
        {
            anotherSlow = nums[anotherSlow];
            slow = nums[slow];
        }

        // Algorithm is Floyd's Tortoise and Hare (Cycle Detection)

        return slow;
    }
};