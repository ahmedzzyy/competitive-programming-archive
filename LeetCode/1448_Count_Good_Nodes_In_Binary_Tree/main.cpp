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
    // We have a current max value and the current node
    // We return the good nodes we have found currently
    int dfs(TreeNode *node, int currentMax)
    {
        if (!node)
            return 0;

        int goodNodesCount = 0;
        if (node->val >= currentMax)
        {
            goodNodesCount = 1; // Current node is a good node
            currentMax = node->val;
        }

        goodNodesCount += dfs(node->left, currentMax);
        goodNodesCount += dfs(node->right, currentMax);

        return goodNodesCount;
    }

public:
    int goodNodes(TreeNode *root)
    {
        return dfs(root, root->val);
    }
};