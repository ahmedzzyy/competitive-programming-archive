#include <vector>

using namespace std;

class Solution
{
private:
    vector<vector<int>> result;

    void backtrack(vector<int> numberList, int currentIndex)
    {
        if (currentIndex == numberList.size())
        {
            result.push_back(numberList);
            return;
        }

        for (int i = currentIndex; i < numberList.size(); i++)
        {
            // Swapping instead of using a visited array

            swap(numberList[currentIndex], numberList[i]);
            backtrack(numberList, currentIndex + 1);
            swap(numberList[currentIndex], numberList[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        backtrack(nums, 0);
        return result;
    }
};