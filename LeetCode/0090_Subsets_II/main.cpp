#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
private:
    void backtrack(vector<int> &nums, vector<vector<int>> &result, vector<int> &current, int start)
    {
        result.push_back(current);
        for (int i = start; i < nums.size(); ++i)
        {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            current.push_back(nums[i]);
            backtrack(nums, result, current, i + 1);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, result, current, 0);
        return result;
    }
};