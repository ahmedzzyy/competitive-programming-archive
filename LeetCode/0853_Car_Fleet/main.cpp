#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        vector<pair<int, int>> positionSpeedMap;
        // (position, speed)

        for (int i = 0; i < position.size(); i++)
        {
            positionSpeedMap.push_back({position[i], speed[i]});
        }

        // Sort in reverse (descending position)
        sort(positionSpeedMap.rbegin(), positionSpeedMap.rend());

        stack<double> carsState;
        for (auto &car : positionSpeedMap)
        {
            double timeRequiredToReachTarget = (double)(target - car.first) / car.second;

            if (!carsState.empty() && timeRequiredToReachTarget <= carsState.top())
            {
                // Case where current car will reach faster than the one in stack
                // Thus this joins the current stack top to become a fleet
                continue;
            }

            carsState.push(timeRequiredToReachTarget);
        }

        return carsState.size();
    }
};