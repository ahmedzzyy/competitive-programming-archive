#include <stack>

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
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> dfsStack;
        TreeNode *currentNode = root;
        int count = 0;

        while (currentNode || !dfsStack.empty())
        {
            while (currentNode)
            {
                // Traverse to the leftmost node
                // and add current nodes to the stack
                dfsStack.push(currentNode);
                currentNode = currentNode->left;
            }

            // Null case reached, backtrack
            currentNode = dfsStack.top();
            dfsStack.pop();
            count++;

            if (count == k)
                return currentNode->val;

            currentNode = currentNode->right;
        }

        return -1;
    }
};