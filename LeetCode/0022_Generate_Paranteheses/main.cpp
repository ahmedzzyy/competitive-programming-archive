#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
    void backtrack(int open, int close, int max, vector<string> &result, string current)
    {
        // no of opening brackets = no of closing brackets = max number of pairs reqd.
        // open can be > than close but close can onlyu be <= open

        if (current.length() == max * 2)
        {
            result.push_back(current);
            return;
        }

        if (open < max)
        {
            backtrack(open + 1, close, max, result, current + "(");
        }
        if (close < open)
        {
            backtrack(open, close + 1, max, result, current + ")");
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        backtrack(0, 0, n, result, "");
        return result;
    }
};