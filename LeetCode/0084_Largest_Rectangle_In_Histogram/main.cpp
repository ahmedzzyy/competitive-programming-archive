#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        int maxArea = 0;
        stack<int> heightIndexStk; // Store index for the height

        for (int i = 0; i <= n; i++)
        {
            while (!heightIndexStk.empty() && (i == n || heights[heightIndexStk.top()] > heights[i]))
            {
                // i == n -> histogram over and a flag trigger to check previous elements
                // OR
                // current height is less than the one on the top of the stack
                int previousHeight = heights[heightIndexStk.top()];
                heightIndexStk.pop();
                // width = (current - 1) - (index of previous lower height + 1) + 1
                int width = heightIndexStk.empty() ? i : i - heightIndexStk.top() - 1;

                maxArea = max(maxArea, previousHeight * width);
            }

            heightIndexStk.push(i);
        }

        return maxArea;
    }
};