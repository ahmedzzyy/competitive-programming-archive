#include <vector>

using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> counts(26, 0);
        for (char task : tasks)
            counts[task - 'A']++;

        int maxCount = 0;
        for (int count : counts)
            maxCount = max(maxCount, count);

        int maxCountTasks = 0;
        for (int count : counts)
        {
            if (count == maxCount)
                maxCountTasks++;
        }

        int partCount = maxCount - 1;
        int partLength = n - (maxCountTasks - 1);
        int emptySlots = partCount * partLength;
        int availableTasks = tasks.size() - (maxCount * maxCountTasks);
        int idles = max(0, emptySlots - availableTasks);

        return tasks.size() + idles;
    }
};