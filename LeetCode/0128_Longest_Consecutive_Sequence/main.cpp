#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // Remove duplicates
        unordered_set<int> numsSet(nums.begin(), nums.end());
        int longest = 0;

        for (auto &num : numsSet)
        {
            if (!numsSet.count(num - 1))
            {
                // Start of the sequence
                int current = num, currentLength = 1;

                while (numsSet.count(current + 1))
                {
                    current++;
                    currentLength++;
                }

                longest = max(longest, currentLength);
            }
        }

        return longest;
    }
};