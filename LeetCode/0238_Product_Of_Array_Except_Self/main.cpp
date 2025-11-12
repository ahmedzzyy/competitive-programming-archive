#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        // Prefix Product X Postfix Product
        vector<int> output(n, 1);

        for (int i = 1; i < n; i++) // Insert prefix product to the arr
        {
            output[i] = output[i - 1] * nums[i - 1];
        }

        int previousPostfix = 1; // Placeholder for the postfix value
        for (int i = n - 1; i >= 0; i--)
        {
            output[i] *= previousPostfix;
            previousPostfix *= nums[i];
        }

        return output;
    }
};