#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> countOfValues; // number -> its frequency

        for (const int &num : nums)
        {
            countOfValues[num]++;
        }

        // Min-Heap
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        // for (auto &entry : countOfValues)
        // {
        //     heap.push({entry.second, entry.first});
        //     if (heap.size() > k)
        //     {
        //         heap.pop();
        //     }
        // }

        // vector<int> result;
        // for (int i = 0; i < k; i++)
        // {
        //     result.push_back(heap.top().second);
        //     heap.pop();
        // }

        // return result;

        // Bucket Sort
        vector<vector<int>> frequency(nums.size() + 1); // Frequency -> Element with the same frequency
        for (const auto &entry : countOfValues)
        {
            frequency[entry.second].push_back(entry.first);
        }

        vector<int> result;
        for (int i = frequency.size() - 1; i > 0; i--)
        {
            for (int n : frequency[i])
            {
                result.push_back(n);

                if (result.size() == k)
                {
                    return result;
                }
            }
        }

        return result;
    }
};