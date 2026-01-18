#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
    bool backtrack(int row, int col, int index, const string &word, vector<vector<char>> &board)
    {
        if (index == word.size())
            return true;

        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index])
            return false;

        char originalValue = board[row][col];
        board[row][col] = '#'; // Mark as visited

        bool found = backtrack(row + 1, col, index + 1, word, board) ||
                     backtrack(row - 1, col, index + 1, word, board) ||
                     backtrack(row, col + 1, index + 1, word, board) ||
                     backtrack(row, col - 1, index + 1, word, board);

        board[row][col] = originalValue;

        return found;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board[0].size(); col++)
            {
                if (backtrack(row, col, 0, word, board))
                    return true;
            }
        }

        return false;
    }
};

// Solution to study
/*
class Solution {
private:
    bool dfs(int i, int j, int idx, vector<vector<char>> &board, string &word) {
        if (board[i][j] != word[idx]) return false;
        if (idx == word.size() - 1) return true;
        board[i][j] = '#';
        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, -1, 1, 0};
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] != '#') {
                if (dfs(x, y, idx+1, board, word)) return true;
            }
        }
        board[i][j] = word[idx];
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        if (word.length() > m*n) return false;
        int boardFreq[123] = {0};
        for (auto i : board) {
            for (auto j : i) {
                boardFreq[j]++;
            }
        }
        int wordFreq[123] = {0};
        for (auto i : word) {
            if (++wordFreq[i] > boardFreq[i]) return false;
        }
        if (wordFreq[word[word.length()-1]] < wordFreq[word[0]]) reverse(word.begin(), word.end());
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(i, j, 0, board, word)) return true;
            }
        }
        return false;
    }
};
*/