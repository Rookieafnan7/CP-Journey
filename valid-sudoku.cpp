// https://leetcode.com/problems/valid-sudoku/description/?source=submission-noac
// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Note:

// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.

// Example 1:

// Input: board =
// [["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: true
// Example 2:

// Input: board =
// [["8","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

// Constraints:

// board.length == 9
// board[i].length == 9
// board[i][j] is a digit 1-9 or '.'.

#include <vector>
using namespace std;
class MySolution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int row[board.size()], col[board.size()], box[board.size()];
        for (int i = 0; i < board.size(); i++)
        {
            row[i] = 0;
            col[i] = 0;
            box[i] = 0;
        }

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board.size(); j++)
                if (board[i][j] == '.')
                    continue;
                else if (!(((row[i] >> (board[i][j] - '0')) & 1) || ((col[j] >> (board[i][j] - '0')) & 1) ||
                           ((box[i / 3 * 3 + j / 3] >> (board[i][j] - '0')) & 1)))
                {
                    row[i] |= 1 << (board[i][j] - '0');
                    col[j] |= 1 << (board[i][j] - '0');
                    box[i / 3 * 3 + j / 3] |= 1 << (board[i][j] - '0');
                }
                else
                    return false;

        return true;
    }
};