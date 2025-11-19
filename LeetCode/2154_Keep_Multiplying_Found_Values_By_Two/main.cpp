#include <vector>

using namespace std;

class Solution
{
public:
    int findFinalValue(vector<int> &nums, int original)
    {
        int current = original;

        while (true)
        {
            bool found = false;

            for (int i = 0; i < nums.size(); i++)
            {
                if (current == nums[i])
                {
                    current *= 2;
                    found = true;
                    break;
                }
            }

            // Not found - break while loop
            if (!found)
            {
                break;
            }
        }

        return current;
    }
};