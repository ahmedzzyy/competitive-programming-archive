#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> maxHeap;
        for (int stone : stones)
            maxHeap.push(stone);

        while (maxHeap.size() > 1)
        {
            int mostHeavyStone = maxHeap.top();
            maxHeap.pop();
            int secondMostHeavyStone = maxHeap.top();
            maxHeap.pop();

            if (mostHeavyStone != secondMostHeavyStone)
                maxHeap.push(mostHeavyStone - secondMostHeavyStone);
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};