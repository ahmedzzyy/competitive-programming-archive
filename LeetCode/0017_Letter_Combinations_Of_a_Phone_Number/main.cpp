#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
    const vector<string> phoneMap = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtrack(int index, const string &digits,
                   string &currentCombination, vector<string> &result)
    {
        if (index == digits.size())
        {
            result.push_back(currentCombination);
            return;
        }

        int digit = digits[index] - '0';
        const string &letters = phoneMap[digit];

        for (char letter : letters)
        {
            currentCombination.push_back(letter);
            backtrack(index + 1, digits, currentCombination, result);
            currentCombination.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};

        vector<string> result;
        string currentCombination;
        backtrack(0, digits, currentCombination, result);

        return result;
    }
};