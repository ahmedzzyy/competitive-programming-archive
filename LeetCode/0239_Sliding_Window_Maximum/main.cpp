#include <deque>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        // Deque -> monotonically decreasing -> front (left) is max
        int n = nums.size();
        vector<int> result(n - k + 1);
        // n-k+1 windows
        deque<int> dq;

        int left = 0, right = 0;

        while (right < n)
        {
            // Pop smaller elements from the back
            while (!dq.empty() && nums[dq.back()] < nums[right])
            {
                dq.pop_back();
            }
            dq.push_back(right);

            // Remove elements out of the current window
            if (left > dq.front())
            {
                dq.pop_front();
            }

            // Record the max for the current window
            if (right + 1 >= k)
            {
                result[left] = nums[dq.front()];
                left++;
            }
            right++;
        }

        return result;
    }
};