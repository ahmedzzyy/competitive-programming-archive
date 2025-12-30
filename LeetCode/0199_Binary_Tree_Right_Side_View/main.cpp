#include <vector>
#include <queue>

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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;

        // Pick one node, go downwards, prefer right
        // FLAWED as it misses nodes that are not along the rightmost path
        // while (root)
        // {
        //     result.push_back(root->val);

        //     if (root->right)
        //     {
        //         root = root->right;
        //     }
        //     else
        //     {
        //         root = root->left;
        //     }
        // }

        if (!root)
            return result;

        queue<TreeNode *> levelQueue;
        levelQueue.push(root);

        while (!levelQueue.empty())
        {
            int levelSize = levelQueue.size();
            TreeNode *currentNode = nullptr;

            for (int i = 0; i < levelSize; i++)
            {
                currentNode = levelQueue.front();
                levelQueue.pop();

                // Add other branches for next level
                if (currentNode->left)
                    levelQueue.push(currentNode->left);
                if (currentNode->right)
                    levelQueue.push(currentNode->right);
            }

            // Last node -> rightmost node
            if (currentNode)
                result.push_back(currentNode->val);
        }

        return result;
    }
};