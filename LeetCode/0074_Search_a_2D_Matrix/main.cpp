#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int topRow = 0, downRow = matrix.size();

        while (topRow < downRow)
        {
            int midRow = (topRow + downRow) / 2;

            if (matrix[midRow].front() > target)
            {
                downRow = midRow;
            }
            else if (matrix[midRow].back() < target)
            {
                topRow = midRow + 1;
            }
            else
            {
                // Binary search in the row
                int leftColumn = 0, rightColumn = matrix[midRow].size();

                while (leftColumn < rightColumn)
                {
                    int midColumn = (leftColumn + rightColumn) / 2;

                    if (matrix[midRow][midColumn] == target)
                    {
                        return true;
                    }
                    else if (matrix[midRow][midColumn] < target)
                    {
                        leftColumn = midColumn + 1;
                    }
                    else
                    {
                        rightColumn = midColumn;
                    }
                }

                return false;
            }
        }

        return false;
    }
};