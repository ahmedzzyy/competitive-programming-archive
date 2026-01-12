#include <string>
#include <vector>

using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    int idx;
    int refs;

    TrieNode() : idx(-1), refs(0), children{} {}

    void addWord(const string &word, int index)
    {
        TrieNode *current = this;

        for (char c : word)
        {
            int i = c - 'a';
            if (!current->children[i])
                current->children[i] = new TrieNode();

            current = current->children[i];
            current->refs++;
        }

        current->idx = index;
    }
};

class Solution
{
private:
    vector<string> result;

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        TrieNode *root = new TrieNode();

        for (int i = 0; i < words.size(); i++)
            root->addWord(words[i], i);

        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board[0].size(); col++)
            {
                dfs(board, root, row, col, words);
            }
        }

        return result;
    }

    void dfs(vector<vector<char>> &board, TrieNode *node, int row, int col, vector<string> &words)
    {
        // Out of bounds or already visited or no matching child
        if (row < 0 || col < 0 || row >= board.size() ||
            col >= board[0].size() || board[row][col] == '*' ||
            !node->children[board[row][col] - 'a'])
            return;

        // Mark the current cell as visited
        char temp = board[row][col];
        board[row][col] = '*';

        // Save the current node before moving to the child
        TrieNode *prev = node;
        node = node->children[temp - 'a'];

        if (node->idx != -1)
        {
            // Found a word
            result.push_back(words[node->idx]);
            node->idx = -1;
            node->refs--;
            if (!node->refs)
            {
                // No more references, prune the Trie
                prev->children[temp - 'a'] = nullptr;
                node = nullptr;
                board[row][col] = temp;
                return;
            }
        }

        dfs(board, node, row + 1, col, words);
        dfs(board, node, row - 1, col, words);
        dfs(board, node, row, col + 1, words);
        dfs(board, node, row, col - 1, words);

        // Restore the current cell
        board[row][col] = temp;
    }
};