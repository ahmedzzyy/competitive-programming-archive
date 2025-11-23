#include <climits>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxSumDivThree(vector<int> &nums)
    {
        // Maximum sum = sum(nums)
        // if sum is divisible by 3, return
        // else remove the smallest number with remainder 1 or 2

        int sum = 0;

        int smallestSumWithRemainder1 = INT_MAX;
        int smallestSumWithRemainder2 = INT_MAX;

        for (const int &num : nums)
        {
            sum += num;

            if (num % 3 == 1)
            {
                // (r = 1) + (r = 1) -> (r = 2)
                const int validSmallestSum = (smallestSumWithRemainder1 != INT_MAX) ? smallestSumWithRemainder1 + num : INT_MAX;
                smallestSumWithRemainder2 = min(smallestSumWithRemainder2, validSmallestSum);
                // smallest number with remainder 1
                smallestSumWithRemainder1 = min(smallestSumWithRemainder1, num);
            }

            if (num % 3 == 2)
            {
                // (r = 2) + (r = 2) -> (r = 1)
                const int validSmallestSum = (smallestSumWithRemainder2 != INT_MAX) ? smallestSumWithRemainder2 + num : INT_MAX;
                smallestSumWithRemainder1 = min(smallestSumWithRemainder1, validSmallestSum);
                // smallest number with remainder 2
                smallestSumWithRemainder2 = min(smallestSumWithRemainder2, num);
            }
        }

        if (sum % 3 == 0)
        {
            return sum;
        }
        else if (sum % 3 == 1)
        {
            // smallestSumWithRemainder1 is not INT_MAX since at least one number exists
            return sum - smallestSumWithRemainder1;
        }
        else
        {
            // smallestSumWithRemainder2 is not INT_MAX since at least one number exists
            return sum - smallestSumWithRemainder2;
        }
    }
};