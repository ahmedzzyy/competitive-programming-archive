#include <vector>

using namespace std;

class Solution
{
private:
    void backtrack(const vector<int> &nums, vector<vector<int>> &result, vector<int> &current, int start)
    {
        result.push_back(current);

        for (int i = start; i < nums.size(); ++i)
        {
            current.push_back(nums[i]);
            backtrack(nums, result, current, i + 1);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> currentSubset;

        backtrack(nums, result, currentSubset, 0);

        return result;
    }
};