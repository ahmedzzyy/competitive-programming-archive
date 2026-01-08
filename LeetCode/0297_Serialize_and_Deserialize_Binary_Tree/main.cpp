#include <string>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "#,";

        string result;

        queue<TreeNode *> nodeProcessingQueue;
        nodeProcessingQueue.push(root);

        while (!nodeProcessingQueue.empty())
        {
            TreeNode *currentNode = nodeProcessingQueue.front();
            nodeProcessingQueue.pop();

            if (currentNode)
            {
                result += to_string(currentNode->val) + ",";
                nodeProcessingQueue.push(currentNode->left);
                nodeProcessingQueue.push(currentNode->right);
            }
            else
            {
                result += "#,";
            }
        }

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return nullptr;

        queue<TreeNode **> nodeProcessingQueue;
        TreeNode *root = nullptr;
        nodeProcessingQueue.push(&root);

        size_t pos = 0;
        while (pos < data.size())
        {
            auto commaPos = data.find(',', pos);
            string token = data.substr(pos, commaPos - pos);
            pos = commaPos + 1;

            TreeNode **currentNodePtr = nodeProcessingQueue.front();
            nodeProcessingQueue.pop();

            if (token == "#")
            {
                *currentNodePtr = nullptr;
            }
            else
            {
                int nodeValue = stoi(token);
                *currentNodePtr = new TreeNode(nodeValue);
                nodeProcessingQueue.push(&((*currentNodePtr)->left));
                nodeProcessingQueue.push(&((*currentNodePtr)->right));
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));