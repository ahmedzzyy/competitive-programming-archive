#include <algorithm>
#include <vector>

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
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty() || inorder.empty())
            return nullptr;

        TreeNode *root = new TreeNode(preorder[0]);
        int nodesOnEitherSide = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + nodesOnEitherSide + 1);
        vector<int> rightPre(preorder.begin() + nodesOnEitherSide + 1, preorder.end());
        vector<int> leftIn(inorder.begin(), inorder.begin() + nodesOnEitherSide);
        vector<int> rightIn(inorder.begin() + nodesOnEitherSide + 1, inorder.end());

        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);

        return root;
    }
};