#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int intersectionSizeTwo(vector<vector<int>> &intervals)
    {
        int result = 0;

        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             {
            if (a[1] == b[1])
            {
                // Tiebreaker: sort by start in descending order
                return a[0] > b[0];
            }
            // Primary sort by end in ascending order
            return a[1] < b[1]; });

        int point1 = -1;
        int point2 = -1;

        for (auto &interval : intervals)
        {
            int left = interval[0], right = interval[1];

            if (point2 < left)
            {
                // Points come before the interval
                result += 2;
                // Two new points
                point1 = right - 1, point2 = right;
            }
            else if (point1 < left)
            {
                // Only one point is covered
                result += 1;
                // Add one new point
                point1 = point2; // Take spot of P2
                point2 = right;
            }
            else
            {
                // Both points are covered; do nothing
            }
        }

        return result;
    }
};