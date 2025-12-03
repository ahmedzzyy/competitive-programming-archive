#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // The key in searching in a rotated sorted array
        // is to check with the left and right pointers
        // in additon of the typical mid pointer
        int left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }

            // Check which sorted portion we are in
            if (nums[left] <= nums[mid])
            {
                // Case: we are in left sorted portion
                if (nums[left] > target || target > nums[mid])
                {
                    // nums[mid] < target < nums[left]
                    // nums[left] -> smallest number in left sorted portion
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            else
            {
                // Case: we are in right sorted portion
                if (target > nums[right] || target < nums[mid])
                {
                    // nums[right] < target < nums[mid]
                    // nums[right] -> largest number in right sorted portion
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }

        return -1;
    }
};