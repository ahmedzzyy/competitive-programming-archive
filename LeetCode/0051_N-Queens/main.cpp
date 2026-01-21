#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
    int columnMask = 0;
    int positiveDiagonalMask = 0;
    int negativeDiagonalMask = 0;

    vector<string> board;
    vector<vector<string>> result;

    void backtrack(int n, int row)
    {
        if (row == n)
        {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            int colBit = 1 << col;
            int posDiagBit = 1 << (row + col);
            int negDiagBit = 1 << (row - col + n - 1);

            // Check if the column or diagonals are already occupied
            if ((columnMask & colBit) || (positiveDiagonalMask & posDiagBit) || (negativeDiagonalMask & negDiagBit))
                continue;

            board[row][col] = 'Q';
            columnMask |= colBit;
            positiveDiagonalMask |= posDiagBit;
            negativeDiagonalMask |= negDiagBit;

            backtrack(n, row + 1);

            board[row][col] = '.';
            columnMask &= ~colBit;
            positiveDiagonalMask &= ~posDiagBit;
            negativeDiagonalMask &= ~negDiagBit;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        board.resize(n, string(n, '.'));
        backtrack(n, 0);
        return result;
    }
};