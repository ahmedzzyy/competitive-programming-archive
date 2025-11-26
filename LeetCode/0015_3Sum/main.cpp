#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;

        int lengthOfNums = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < lengthOfNums; i++)
        {
            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            if (nums[i] > 0)
            {
                // Only positive numbers remain
                break;
            }

            int currentNumber = nums[i];
            int left = i + 1, right = lengthOfNums - 1;

            // 2 Pointer solution for Two Sum II
            while (left < right)
            {
                int current3Sum = currentNumber + nums[left] + nums[right];

                if (current3Sum > 0)
                {
                    right--;
                }
                else if (current3Sum < 0)
                {
                    left++;
                }
                else
                {
                    result.push_back({currentNumber, nums[left], nums[right]});

                    // Next possible combination
                    left++;
                    right--;

                    // Skip duplicates for left pointer
                    while (left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                }
            }
        }

        return result;
    }
};