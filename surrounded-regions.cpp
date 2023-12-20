// Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// Example 1:

// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
// Explanation: Notice that an 'O' should not be flipped if:
// - It is on the border, or
// - It is adjacent to an 'O' that should not be flipped.
// The bottom 'O' is on the border, so it is not flipped.
// The other three 'O' form a surrounded region, so they are flipped.
// Example 2:

// Input: board = [["X"]]
// Output: [["X"]]

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 200
// board[i][j] is 'X' or 'O'.

#include <vector>
using namespace std;
class BestSolution
{
public:
    void helper(vector<vector<char>> &board, int i, int j)
    {
        if (board[i][j] != 'O')
            return;
        else
        {
            board[i][j] = 'K';
            if (i > 0 && board[i - 1][j] == 'O')
                helper(board, i - 1, j);
            if (i < board.size() - 1 && board[i + 1][j] == 'O')
                helper(board, i + 1, j);
            if (j > 0 && board[i][j - 1] == 'O')
                helper(board, i, j - 1);
            if (j < board[0].size() - 1 && board[i][j + 1] == 'O')
                helper(board, i, j + 1);
            return;
        };
    }
    void solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][0] == 'O')
                helper(board, i, 0);
            if (board[i][board[0].size() - 1] == 'O')
                helper(board, i, board[0].size() - 1);
        }
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[0][j] == 'O')
                helper(board, 0, j);
            if (board[board.size() - 1][j])
                helper(board, board.size() - 1, j);
        }
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] != 'K')
                    board[i][j] = 'X';
                else
                    board[i][j] = 'O';
    }
};