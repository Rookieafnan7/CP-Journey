// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

// Example 1:

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
// Example 2:

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true
// Example 3:

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false

// Constraints:

// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board and word consists of only lowercase and uppercase English letters.

// Follow up: Could you use search pruning to make your solution faster with a larger board?

// with visited array

class BetterSolution
{
public:
    bool solve(int index, int row, int col, int m, int n, vector<vector<char>> &board, string word, string ds, vector<vector<int>> &vis)
    {

        // base case
        if (index == word.length())
        {
            return true;
        }

        // handle edge cases
        if (row < 0 || col < 0 || row >= m || col >= n)
        {
            return false;
        }

        // down
        if (row + 1 < m && vis[row + 1][col] == 0 && board[row + 1][col] == word[index])
        {

            vis[row][col] = 1;

            bool ans1 = solve(index + 1, row + 1, col, m, n, board, word, ds + board[row][col], vis);

            if (ans1 == true)
            {
                return true;
            }

            vis[row][col] = 0;
        }

        // left
        if (col - 1 >= 0 && vis[row][col - 1] == 0 && board[row][col - 1] == word[index])
        {
            vis[row][col] = 1;

            bool ans2 = solve(index + 1, row, col - 1, m, n, board, word, ds + board[row][col], vis);

            if (ans2 == true)
            {
                return true;
            }

            vis[row][col] = 0;
        }

        // right
        if (col + 1 < n && vis[row][col + 1] == 0 && board[row][col + 1] == word[index])
        {
            vis[row][col] = 1;

            bool ans3 = solve(index + 1, row, col + 1, m, n, board, word, ds + board[row][col], vis);

            if (ans3 == true)
            {
                return true;
            }

            vis[row][col] = 0;
        }

        // up
        if (row - 1 >= 0 && vis[row - 1][col] == 0 && board[row - 1][col] == word[index])
        {
            vis[row][col] = 1;

            bool ans4 = solve(index + 1, row - 1, col, m, n, board, word, ds + board[row][col], vis);

            if (ans4 == true)
            {
                return true;
            }

            vis[row][col] = 0;
        }

        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {

        int m = board.size();    // row
        int n = board[0].size(); // col

        int index = 0;

        vector<vector<int>> vis(m, vector<int>(n, 0));

        string ds = "";

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {

                if (board[row][col] == word[index] && solve(index + 1, row, col, m, n, board, word, ds + board[row][col], vis))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

class MySolution
{
public:
    int helper(vector<vector<char>> &board, string &word, int &index, int i, int j)
    {
        // cout<<i<<" "<<j<<" "<<endl;
        if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0)
            return index;
        char store = board[i][j];

        // cout<<"pass"<<endl;
        // if(board[i][j] == '#') return index;
        bool flag = false;
        if (board[i][j] == '#')
            return index;
        else if (board[i][j] == word[index])
        {
            index++;
            flag = true;
        }
        else
            return index;
        board[i][j] = '#';
        if (index == word.size())
            return index;
        int maxCount = index;
        maxCount = max(maxCount, helper(board, word, index, i + 1, j));
        maxCount = max(maxCount, helper(board, word, index, i, j + 1));
        maxCount = max(maxCount, helper(board, word, index, i - 1, j));
        maxCount = max(maxCount, helper(board, word, index, i, j - 1));

        board[i][j] = store;
        if (flag)
            index--;

        return maxCount;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        // cout<<board.size()<<' '<<board[0].size()<<endl;
        if (word.size() == 0)
            return true;
        int index = 0;
        int count = 0;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                count = max(count, helper(board, word, index, i, j));
        // helper(board, word, index, 0, 0);
        if (count == word.size())
            return true;
        else
            return false;
    }
};