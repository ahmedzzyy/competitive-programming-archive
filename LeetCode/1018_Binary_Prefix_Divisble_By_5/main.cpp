#include <vector>

using namespace std;

class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int> &nums)
    {
        vector<bool> result;

        // Storing the entire prefix value -> leading to overflow for large inputs
        // int currentPrefix = 0;

        // We store the prefix value remainder when divided by 5
        int currentPrefixRemainder = 0;

        for (int num : nums)
        {
            // currentPrefix = (currentPrefix << 1) + num;
            currentPrefixRemainder = ((currentPrefixRemainder << 1) + num) % 5;
            result.push_back(currentPrefixRemainder == 0);
        }

        return result;
    }
};