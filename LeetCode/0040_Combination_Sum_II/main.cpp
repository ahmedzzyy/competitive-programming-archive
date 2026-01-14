#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<vector<int>> result;

    void backtrack(int target, int start, const vector<int> &candidates, vector<int> &current)
    {
        if (target == 0)
        {
            result.push_back(current);
            return;
        }

        if (target < 0)
            return;

        for (int i = start; i < candidates.size(); ++i)
        {
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1])
            {
                continue;
            }

            current.push_back(candidates[i]);

            backtrack(target - candidates[i], i + 1, candidates, current);
            // i + 1 because each number can only be used once

            current.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        // Constraints:
        // 1. no duplicate combinations
        // 2. each number can only be used once, or the times it appears in candidates

        sort(candidates.begin(), candidates.end());
        vector<int> current;
        backtrack(target, 0, candidates, current);
        return result;
    }
};