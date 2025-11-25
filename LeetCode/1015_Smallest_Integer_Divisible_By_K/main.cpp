class Solution
{
public:
    int smallestRepunitDivByK(int k)
    {
        if (k % 2 == 0 || k % 5 == 0)
        {
            // 2, 4, 6, 8, ... - divide only even numbers
            // 5, 10, 15, ... - divide ending digits 0 and 5
            return -1;
        }

        if (k == 1)
        {
            return 1;
        }

        int remainder = 0;

        // Only k different remainders are possible
        for (int length = 1; length <= k; length++)
        {
            // Leetcode - Note: n may not fit in a 64-bit signed integer.
            // This hints us to not actually build the number n.

            // We keep track of the remainder
            remainder = (remainder * 10 + 1) % k;

            if (remainder == 0)
            {
                return length;
            }
        }

        return -1;
    }
};