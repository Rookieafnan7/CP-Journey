// Given an m x n matrix, return all elements of the matrix in spiral order.

// Example 1:

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:

// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        int dir = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int total = m * n;
        int count = 0;
        vector<int> tr(4, 0);
        while (count < total)
        {
            if (dir == 0)
            {
                for (int i = tr[3]; i < n - tr[1]; i++)
                {
                    res.push_back(matrix[tr[0]][i]);
                    count++;
                }
                tr[0]++;
            }
            else if (dir == 1)
            {
                for (int i = tr[0]; i < m - tr[2]; i++)
                {
                    res.push_back(matrix[i][n - 1 - tr[1]]);
                    count++;
                }
                tr[1]++;
            }
            else if (dir == 2)
            {
                for (int i = n - tr[1] - 1; i >= tr[3]; i--)
                {
                    res.push_back(matrix[m - tr[2] - 1][i]);
                    count++;
                }
                tr[2]++;
            }
            else if (dir == 3)
            {
                for (int i = m - tr[2] - 1; i >= tr[0]; i--)
                {
                    res.push_back(matrix[i][tr[3]]);
                    count++;
                }
                tr[3]++;
            }
            dir = (dir + 1) % 4;
        }
        return res;
    }
};