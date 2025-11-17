#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        // Brute Force
        // vector<int> warmerResult;

        // for (int i = 0; i < temperatures.size(); i++)
        // {
        //     int daysToWarmTemp = 0;

        //     for (int j = i + 1; j < temperatures.size(); j++)
        //     {
        //         if (temperatures[i] < temperatures[j])
        //         {
        //             daysToWarmTemp = j - i;
        //             break;
        //         }
        //     }

        //     warmerResult.push_back(daysToWarmTemp);
        // }

        // return warmerResult;

        // Stack
        // vector<int> warmerTempInDays(temperatures.size(), 0);
        // stack<pair<int, int>> temperatureStk; // {temperature, index}

        // for (int i = 0; i < temperatures.size(); i++)
        // {
        //     int currentTemp = temperatures[i];

        //     while (!temperatureStk.empty() && temperatureStk.top().first < currentTemp)
        //     {
        //         int j = temperatureStk.top().second;
        //         temperatureStk.pop();

        //         warmerTempInDays[j] = i - j;
        //     }

        //     temperatureStk.push({currentTemp, i});
        // }

        // return warmerTempInDays;

        // Dynamic Programming
        int n = temperatures.size();
        // Take the resultant array as our DP array
        // Check from last and jump smartly with the next warmer day using our DP array
        vector<int> warmerTempInDays(n, 0);

        // Start from 2nd last
        for (int i = n - 2; i >= 0; i--)
        {
            int j = i + 1; // Index for next warm day initialized to next day

            // While next day available
            while (j < n)
            {
                if (temperatures[j] > temperatures[i])
                {
                    // Found next warmer day
                    break;
                }

                if (warmerTempInDays[j] == 0)
                {
                    // No next warmer day in our DP array
                    j = n;
                    break;
                }

                j += warmerTempInDays[j];
            }

            if (j < n)
            {
                warmerTempInDays[i] = j - i;
            }
        }

        return warmerTempInDays;
    }
};