// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *current = root;

        while (current)
        {
            if (p->val < current->val && q->val < current->val)
            {
                // Same side (left)
                current = current->left;
            }
            else if (p->val > current->val && q->val > current->val)
            {
                // Same side (right)
                current = current->right;
            }
            else
            {
                // split - LCA
                return current;
            }
        }

        return nullptr;
    }
};