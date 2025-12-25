#include <algorithm>
#include <cmath>
#include <utility>

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
    pair<bool, int> checkBalanced(TreeNode *node)
    {
        if (!node)
            return {true, 0};

        auto left = checkBalanced(node->left);
        auto right = checkBalanced(node->right);

        bool is_balanced = left.first && right.first && abs(left.second - right.second) <= 1;
        int height = max(left.second, right.second) + 1;

        return {is_balanced, height};
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return checkBalanced(root).first;
    }
};
