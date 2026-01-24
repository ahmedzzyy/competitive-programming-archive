#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        // Min Heap
        auto compareDistances = [](const vector<int> &a, const vector<int> &b)
        {
            return (a[0] * a[0] + a[1] * a[1]) > (b[0] * b[0] + b[1] * b[1]);
        };

        // decltype to define the type of the comparator
        priority_queue<vector<int>, vector<vector<int>>, decltype(compareDistances)> minHeap(compareDistances);

        for (const auto &point : points)
            minHeap.push(point);

        vector<vector<int>> result;
        for (int i = 0; i < k; ++i)
        {
            result.push_back(minHeap.top());
            minHeap.pop();
        }

        return result;
    }
};