#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // Brute Force
        // // - Row wise
        // for (int row = 0; row < 9; row++)
        // {
        //     unordered_set<char> seen;

        //     // (Check each column of the row)
        //     for (int i = 0; i < 9; i++)
        //     {
        //         if (board[row][i] == '.')
        //             continue;
        //         if (seen.count(board[row][i]))
        //             return false;

        //         seen.insert(board[row][i]);
        //     }
        // }

        // // - Column wise
        // for (int col = 0; col < 9; col++)
        // {
        //     unordered_set<char> seen;

        //     // (Check each row of the column)
        //     for (int i = 0; i < 9; i++)
        //     {
        //         if (board[i][col] == '.')
        //             continue;
        //         if (seen.count(board[i][col]))
        //             return false;

        //         seen.insert(board[i][col]);
        //     }
        // }

        // // - Square wise
        // for (int square = 0; square < 9; square++)
        // {
        //     unordered_set<char> seen;

        //     // (Check each square)
        //     for (int i = 0; i < 3; i++)
        //     {
        //         for (int j = 0; j < 3; j++)
        //         {
        //             int row = (square / 3) * 3 + i;
        //             int col = (square % 3) * 3 + j;

        //             if (board[row][col] == '.')
        //                 continue;
        //             if (seen.count(board[row][col]))
        //                 return false;

        //             seen.insert(board[row][col]);
        //         }
        //     }
        // }

        // return true;

        // Hash Set for each row, col, square
        // unordered_map<int, unordered_set<char>> rows, cols;
        // map<pair<int, int>, unordered_set<char>> squares;

        // for (int row = 0; row < 9; row++)
        // {
        //     for (int col = 0; col < 9; col++)
        //     {
        //         if (board[row][col] == '.')
        //             continue;

        //         pair<int, int> squarePositionIndex = {row / 3, col / 3};

        //         if (rows[row].count(board[row][col]) || cols[col].count(board[row][col]) || squares[squarePositionIndex].count(board[row][col]))
        //         {
        //             return false;
        //         }

        //         rows[row].insert(board[row][col]);
        //         cols[col].insert(board[row][col]);
        //         squares[squarePositionIndex].insert(board[row][col]);
        //     }
        // }

        // return true;

        // Bit Masking
        int rows[9] = {0};
        int cols[9] = {0};
        int squares[9] = {0};

        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] == '.')
                    continue;

                int val = board[row][col] - '1';
                const int squareBitPosition = (row / 3) * 3 + (col / 3);

                if ((rows[row] & (1 << val)) || (cols[col] & (1 << val)) || (squares[squareBitPosition] & (1 << val)))
                    return false;

                rows[row] |= (1 << val);
                cols[col] |= (1 << val);
                squares[squareBitPosition] |= (1 << val);
            }
        }

        return true;
    }
};