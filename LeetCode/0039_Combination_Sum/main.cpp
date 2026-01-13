#include <vector>

using namespace std;

class Solution
{
private:
    vector<vector<int>> result;

    void backtrack(vector<int> &candidates, int target, vector<int> &combination, int start)
    {
        if (target == 0)
        {
            result.push_back(combination);
            return;
        }

        if (target < 0)
            return;

        for (int i = start; i < candidates.size(); i++)
        {
            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], combination, i);
            combination.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> combination;
        backtrack(candidates, target, combination, 0);
        return result;
    }
};