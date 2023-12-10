// https://leetcode.com/problems/number-of-islands/description/?envType=study-plan-v2&envId=top-interview-150

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.

#include <iostream>
#include <vector>

using namespace std;

class BestSolution
{
private:
    int m;
    int n;
    const vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    int numIslands(vector<vector<char>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++count;
                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }

    void dfs(vector<vector<char>> &grid, int row, int col)
    {
        grid[row][col] = '0';

        for (const auto &direction : directions)
        {
            int nextRow = row + direction[0];
            int nextCol = col + direction[1];

            if (isValid(grid, nextRow, nextCol) && grid[nextRow][nextCol] == '1')
                dfs(grid, nextRow, nextCol);
        }
    }

    bool isValid(vector<vector<char>> &grid, int row, int col)
    {
        return row >= 0 && col >= 0 && row < m && col < n;
    }
};

class Solution
{
public:
    void checkAdjacent(vector<vector<char>> &grid, vector<vector<int>> &refGrid, int &islands, int i, int j)
    {
        if (i < 0 || i >= refGrid.size())
            return;
        if (j < 0 || j >= refGrid[0].size())
            return;
        if (grid[i][j] == '1' && refGrid[i][j] == 0)
        {
            refGrid[i][j] = islands;
            checkAdjacent(grid, refGrid, islands, i - 1, j);
            checkAdjacent(grid, refGrid, islands, i + 1, j);
            checkAdjacent(grid, refGrid, islands, i, j - 1);
            checkAdjacent(grid, refGrid, islands, i, j + 1);
            return;
        }
        else
            return;
    }

    int numIslands(vector<vector<char>> &grid)
    {
        vector<vector<int>> refGrid(grid.size(), vector<int>(grid[0].size(), 0));
        int islands = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1' && refGrid[i][j] == 0)
                {
                    ++islands;
                    checkAdjacent(grid, refGrid, islands, i, j);
                }
                else
                    continue;
            }
        }
        return islands;
    }
};
