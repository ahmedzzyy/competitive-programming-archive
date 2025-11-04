#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        // Brute-Force
        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         if (nums[i] == nums[j]) {
        //             return true;
        //         }
        //     }
        // }

        // return false;

        // Pre-sorting and Partial Brute-Force
        // [Faster than the other implementations]
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == nums.size() - 1)
                continue;

            if (nums[i] == nums[i + 1])
            {
                return true;
            }
        }

        // return false;

        // Hash-Set Conversion and Intermediate insertion checks
        // unordered_set<int> hashSet;
        // for (int num : nums)
        // {
        //     if (hashSet.count(num))
        //     {
        //         return true;
        //     }

        //     hashSet.insert(num);
        // }

        // return false;

        // Hash-Set Conversion and final length check
        // return unordered_set<int>(nums.begin(), nums.end()).size() != nums.size();
    }
};