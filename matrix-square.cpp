// Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 

// Example 1:


// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 4
// Example 2:


// Input: matrix = [["0","1"],["1","0"]]
// Output: 1
// Example 3:

// Input: matrix = [["0"]]
// Output: 0
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 300
// matrix[i][j] is '0' or '1'.



class BestSolution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        int maxLen = INT_MIN;
        for (int i = matrix.size() - 1; i >= 0; i--)
        {
            for (int j = matrix[0].size() - 1; j >= 0; j--)
            {
                if (matrix[i][j] == '1')
                    dp[i][j] = 1 + min(dp[i + 1][j], min(dp[i][j + 1], dp[i + 1][j + 1]));
                maxLen = max(maxLen, dp[i][j]);
            }
        }
        if (maxLen == INT_MIN)
            return 0;
        else
            return maxLen * maxLen;
    }
};

class MyBadSolution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        vector<vector<int>> dph(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0)), dpb(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        int maxLen = INT_MIN;
        for (int i = matrix.size() - 1; i >= 0; i--)
        {
            for (int j = matrix[0].size() - 1; j >= 0; j--)
            {
                cout << "i " << i << " j " << j << endl;
                if (matrix[i][j] - '0')
                    dpb[i][j] = (int)(matrix[i][j] - '0') + dpb[i][j + 1];
                if (matrix[i][j] - '0')
                    dph[i][j] = (int)(matrix[i][j] - '0') + dph[i + 1][j];
                int temp = min(dpb[i][j], dph[i][j]);
                cout << "temp " << temp << endl;
                int x, y;
                int save = 0;
                for (x = 0; x < temp; x++)
                {
                    if (min(dpb[i + x][j + x], dph[i + x][j + x]) >= temp - x)
                    {
                        continue;
                    }
                    else
                    {
                        temp = min(dpb[i + x][j + x], dph[i + x][j + x]) + x;
                    }
                }
                maxLen = max(maxLen, temp);
                cout << "max " << maxLen << endl;
            }
        }
        if (maxLen == INT_MIN)
            return 0;
        else
            return maxLen * maxLen;
    }
};