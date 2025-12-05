#include <climits>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> &longer = nums1.size() >= nums2.size() ? nums1 : nums2;
        vector<int> &shorter = nums1.size() < nums2.size() ? nums1 : nums2;
        int totalSize = nums1.size() + nums2.size();
        int midIndex = (totalSize + 1) / 2;

        int left = 0, right = shorter.size();
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int midLonger = midIndex - mid;

            // Elements around the partition in the shorter array
            int shorterLeft = (mid > 0) ? shorter[mid - 1] : INT_MIN;
            int shorterRight = (mid < shorter.size()) ? shorter[mid] : INT_MAX;

            // Elements around the partition in the longer array
            int longerLeft = (midLonger > 0) ? longer[midLonger - 1] : INT_MIN;
            int longerRight = (midLonger < longer.size()) ? longer[midLonger] : INT_MAX;

            if (shorterLeft <= longerRight && longerLeft <= shorterRight)
            {
                // Correct partition found
                if (totalSize % 2 == 0)
                {
                    return (max(shorterLeft, longerLeft) + min(shorterRight, longerRight)) / 2.0;
                }

                return max(shorterLeft, longerLeft);
            }
            else if (shorterLeft > longerRight)
            {
                // Move partition in shorter array to the left
                right = mid - 1;
            }
            else
            {
                // Move partition in shorter array to the right
                left = mid + 1;
            }
        }

        return 0.0;
    }
};