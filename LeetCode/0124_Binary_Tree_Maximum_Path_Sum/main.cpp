#include <algorithm>
#include <climits>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    int maxSum = INT_MIN;

    int findMaxPathSum(TreeNode *node)
    {
        if (!node)
            return 0;

        int leftMax = max(0, findMaxPathSum(node->left));
        int rightMax = max(0, findMaxPathSum(node->right));

        int currentPathSum = node->val + leftMax + rightMax;
        maxSum = max(maxSum, currentPathSum);
        return node->val + max(leftMax, rightMax);
    }

public:
    int maxPathSum(TreeNode *root)
    {
        findMaxPathSum(root);
        return maxSum;
    }
};