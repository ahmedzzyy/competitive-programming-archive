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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;

        if (!root)
            return result;

        queue<TreeNode *> currentLevelQueue;
        currentLevelQueue.push(root);

        while (!currentLevelQueue.empty())
        {
            int levelSize = currentLevelQueue.size();
            vector<int> currentLevelValues;

            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *currentNode = currentLevelQueue.front();
                currentLevelQueue.pop();
                currentLevelValues.push_back(currentNode->val);

                if (currentNode->left)
                    currentLevelQueue.push(currentNode->left);
                if (currentNode->right)
                    currentLevelQueue.push(currentNode->right);
            }

            result.push_back(currentLevelValues);
        }

        return result;
    }
};