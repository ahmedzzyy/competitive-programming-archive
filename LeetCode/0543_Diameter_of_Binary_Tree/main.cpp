#include <algorithm>

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
    int maxDiameter = 0;

    int depth(TreeNode *node, int &maxDiameter)
    {
        if (!node)
            return 0;

        int leftDepth = depth(node->left, maxDiameter);
        int rightDepth = depth(node->right, maxDiameter);

        // diameter = left depth + right depth
        maxDiameter = max(maxDiameter, leftDepth + rightDepth);

        return 1 + max(leftDepth, rightDepth);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int maxDiameter = 0;
        depth(root, maxDiameter);
        return maxDiameter;
    }
};