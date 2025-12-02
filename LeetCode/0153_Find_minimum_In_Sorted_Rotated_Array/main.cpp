#include <vector>

using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        int minimum = nums[0];

        while (left <= right)
        {
            // Key is to use the left and right pointers to determine the sorted portion
            if (nums[left] < nums[right])
            {
                minimum = min(minimum, nums[left]);
                break;
            }

            int mid = left + (right - left) / 2;
            minimum = min(minimum, nums[mid]);

            if (nums[mid] >= nums[left])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return minimum;
    }
};