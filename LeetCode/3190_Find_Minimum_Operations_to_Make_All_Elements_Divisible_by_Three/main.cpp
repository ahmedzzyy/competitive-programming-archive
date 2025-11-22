#include <vector>

using namespace std;

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int notDivisibleByThreeCount = 0;

        for (int &num : nums)
        {
            if (num % 3 != 0)
            {
                notDivisibleByThreeCount++;
            }
        }

        // 0 operation for divisible numbers
        // Only 1 operation required for not divisible
        // num % 3 = 1 -> num - 1
        // num % 3 = 2 -> num + 1
        return notDivisibleByThreeCount;
    }
};