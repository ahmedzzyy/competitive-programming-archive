#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // Brute Force
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     for (int j = i + 1; j < nums.size(); j++)
        //     {
        //         if (nums[i] + nums[j] == target)
        //         {
        //             return {i, j};
        //         }
        //     }
        // }

        // Pre Sorting and Two-Pointer
        // (Almost like binary search)
        // vector<pair<int, int>> valueIndexPairs;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     valueIndexPairs.push_back({nums[i], i});
        // }

        // sort(valueIndexPairs.begin(), valueIndexPairs.end());

        // int left = 0, right = nums.size() - 1;
        // while (left < right)
        // {
        //     const int currentSum = valueIndexPairs[left].first + valueIndexPairs[right].first;
        //     if (currentSum == target)
        //     {

        //         return {min(valueIndexPairs[left].second, valueIndexPairs[right].second), max(valueIndexPairs[left].second, valueIndexPairs[right].second)};
        //     }
        //     else if (currentSum < target)
        //     {
        //         left++;
        //     }
        //     else
        //     {
        //         right--;
        //     }
        // }

        // Hash Map Use
        // (Two Pass)
        // unordered_map<int, int> valueIndexMap; // value -> index

        // for (int i = 0; i < nums.size(); i++)
        // {
        //     valueIndexMap.insert({nums[i], i});
        // }

        // for (int i = 0; i < nums.size(); i++)
        // {
        //     int differenceNeeded = target - nums[i];
        //     if (valueIndexMap.count(differenceNeeded) && valueIndexMap[differenceNeeded] != i)
        //     {
        //         return {i, valueIndexMap[differenceNeeded]};
        //     }
        // }

        // (One Pass)
        unordered_map<int, int> valueIndexMap; // value -> index

        for (int i = 0; i < nums.size(); i++)
        {
            int differenceNeeded = target - nums[i];

            if (valueIndexMap.count(differenceNeeded))
            {
                return {valueIndexMap[differenceNeeded], i};
            }

            valueIndexMap.insert({nums[i], i});
        }

        // Common for all solutions, solution is always present, we require this for return type satisfaction
        return {};
    }
};