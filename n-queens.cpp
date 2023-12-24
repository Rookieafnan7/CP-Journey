// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return the number of distinct solutions to the n-queens puzzle.

// Example 1:

// Input: n = 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
// Example 2:

// Input: n = 1
// Output: 1

// Constraints:

// 1 <= n <= 9

#include <vector>
#include <string>
using namespace std;

// using hashing
// i + j for left lower diagonal
// (n - 1) + j - i for upper left diagonal
class BetterSolution
{

    /*
        Time Complexity : O(n!)
        Space Complexity : O(n^2) + O(2*n) + O(n)
    */

private:
    vector<int> upperLeftDiagnal;
    vector<int> upperRightDiagnal;
    vector<int> upperCol;

    int res = 0;
    vector<string> board;

    void helper(int row, int size)
    {
        if (row == size)
        {
            res++;
            return;
        }

        for (int col = 0; col < size; col++)
        {
            if (upperCol[col] == 0 and
                upperLeftDiagnal[row + col] == 0 and
                upperRightDiagnal[(size - 1) + col - row] == 0)
            {
                board[row][col] = 'Q';
                upperCol[col] = upperLeftDiagnal[row + col] = upperRightDiagnal[(size - 1) + col - row] = 1;
                helper(row + 1, size);
                upperCol[col] = upperLeftDiagnal[row + col] = upperRightDiagnal[(size - 1) + col - row] = 0;
                board[row][col] = '.';
            }
        }
    }

public:
    int totalNQueens(int n)
    {
        upperLeftDiagnal.resize(2 * n - 1, 0);
        upperRightDiagnal.resize(2 * n - 1, 0);
        upperCol.resize(n, 0);

        board.resize(n);
        string s(n, '.');

        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }

        // row, size
        helper(0, n);

        return res;
    }
};

class MYSolution
{
public:
    bool isSafe(vector<vector<int>> &m, int &row, int &col)
    {
        int i, j;
        for (i = 0; i < col; i++)
            if (m[row][i] == 1)
                return false;
        for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (m[i][j] == 1)
                return false;
        for (i = row, j = col; i < m.size() && j >= 0; i++, j--)
            if (m[i][j] == 1)
                return false;
        return true;
    }
    bool helper(vector<vector<int>> &m, int &count, int col)
    {
        if (col >= m.size())
        {
            count++;
            return true;
        }
        bool save = false;
        for (int i = 0; i < m.size(); i++)
        {
            if (isSafe(m, i, col))
            {
                m[i][col] = 1;
                if (helper(m, count, col + 1))
                    save = save || true;
                m[i][col] = 0;
            }
        }
        return save;
    }
    int totalNQueens(int n)
    {
        vector<vector<int>> m(n, vector<int>(n, 0));
        int count = 0;
        helper(m, count, 0);
        return count;
    }
};
