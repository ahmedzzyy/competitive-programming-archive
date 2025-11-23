#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        // Already implemented for presorted approach in 0001_TwoSum

        int left = 0, right = numbers.size() - 1;

        while (left < right)
        {
            const int currentSum = numbers[left] + numbers[right];

            if (currentSum == target)
            {
                return {left + 1, right + 1};
            }
            else if (currentSum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return {};
    }
};