#include <climits>

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
    bool validateSubtree(TreeNode *currentNode, int leftLimit, int rightLimit)
    {
        if (!currentNode)
            return true;

        // Not within the range allowed in the subtree structure
        if (!(leftLimit < currentNode->val && currentNode->val < rightLimit))
            return false;

        // Update ranges
        return validateSubtree(currentNode->left, leftLimit, currentNode->val) && validateSubtree(currentNode->right, currentNode->val, rightLimit);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return validateSubtree(root, INT_MIN, INT_MAX);
    }
};
