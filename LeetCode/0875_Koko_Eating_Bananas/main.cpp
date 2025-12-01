#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        // Minimum possible eating speed = 1
        // Maximum possible eating speed = max number of bananas in a pile
        // as all piles are indirectly eaten

        // Brute Force
        // (Time Limit Exceeded)
        // int maxPile = 0;
        // for (const int &pile : piles)
        // {
        //     if (pile > maxPile)
        //     {
        //         maxPile = pile;
        //     }
        // }

        // for (int speed = 1; speed <= maxPile; speed++)
        // {
        //     long long hoursSpent = 0;
        //     for (const int &pile : piles)
        //     {
        //         hoursSpent += (pile + speed - 1) / speed; // Ceiling division
        //     }

        //     // Increasing order, so the first speed that satisfies is the answer
        //     if (hoursSpent <= h)
        //     {
        //         return speed;
        //     }
        // }

        // return maxPile; // Satisfy return type

        // Binary Search
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        int result = right; // maximum possible speed

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            long long hoursSpent = 0;
            for (const int &pile : piles)
            {
                hoursSpent += (pile + mid - 1) / mid; // Ceiling division
            }

            if (hoursSpent <= h)
            {
                result = mid; // Update result
                right = mid;  // Try to find a smaller valid speed
            }
            else
            {
                left = mid + 1; // Increase speed
            }
        }

        return result;
    }
};