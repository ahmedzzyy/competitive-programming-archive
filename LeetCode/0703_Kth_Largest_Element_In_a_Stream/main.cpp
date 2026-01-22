#include <queue>
#include <vector>

using namespace std;

class KthLargest
{
private:
    int k;
    // Heap coz the need is to track the largest k numbers
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        for (int num : nums)
        {
            minHeap.push(num);

            // No need to keep more elements than needed
            if (minHeap.size() > k)
                minHeap.pop();
        }
    }

    int add(int val)
    {
        minHeap.push(val);

        // No need to keep more elements than needed
        if (minHeap.size() > k)
            minHeap.pop();

        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */