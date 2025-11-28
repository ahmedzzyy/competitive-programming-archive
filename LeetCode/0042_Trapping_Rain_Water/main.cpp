#include <vector>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        // The key to the logic is to iterate block-by-block
        // that is go index-by-index

        // Water stored at each block looks at the left and right boundary
        // the boundary is the technically the highest block on each side

        // So at any index i (except the edges - cause they can't store water)
        // We find the maxHeight from the left and right
        // That helps define the boundaries
        // BUT current elevation also reduces it

        // Therefore water stored at index i is:
        // water[i] = min(maxLeft, maxRight) - height[i]

        // --- SOLUTION --- //
        int n = height.size();
        if (n <= 2)
        {
            // Can't store water with less than 3 blocks
            return 0;
        }

        int totalWater = 0;

        int leftIndex = 0, rightIndex = n - 1;
        int maxLeftHeight = height[leftIndex], maxRightHeight = height[rightIndex];

        while (leftIndex < rightIndex)
        {
            if (maxLeftHeight < maxRightHeight)
            {
                // min(maxLeft, maxRight) is maxLeft

                leftIndex++;
                // Update max left height
                maxLeftHeight = max(maxLeftHeight, height[leftIndex]);

                totalWater += max(0, maxLeftHeight - height[leftIndex]);
                // maxLeftHeight >= height[leftIndex] coz of the earlier updation
            }
            else
            {
                // min(maxLeft, maxRight) is maxRight

                rightIndex--;
                // Update max right height
                maxRightHeight = max(maxRightHeight, height[rightIndex]);

                totalWater += max(0, maxRightHeight - height[rightIndex]);
                // maxRightHeight >= height[rightIndex] coz of the earlier updation
            }
        }

        return totalWater;
    }
};