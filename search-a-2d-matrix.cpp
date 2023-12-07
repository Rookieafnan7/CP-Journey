// https : // leetcode.com/problems/search-a-2d-matrix/submissions/1114450321/?envType=study-plan-v2&envId=top-interview-150

// You are given an m x n integer matrix matrix with the following two properties :

//     Each row is sorted in non -
//     decreasing order.The first integer of each row is greater than the last integer of the previous row.Given an integer target,
//     return true if target is in matrix or false otherwise.

//                                           You must write a solution in O(log(m * n)) time complexity.

//                                           Example 1 :

//     Input : matrix = [ [ 1, 3, 5, 7 ], [ 10, 11, 16, 20 ], [ 23, 30, 34, 60 ] ],
//             target = 3 Output : true Example 2 :

//     Input : matrix = [ [ 1, 3, 5, 7 ], [ 10, 11, 16, 20 ], [ 23, 30, 34, 60 ] ],
//             target = 13 Output : false

//                                  Constraints :

//     m == matrix.length n == matrix[i].length 1 <= m,
//             n <= 100 - 104 <= matrix[i][j], target <= 104

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0)
            return false;
        if (matrix[0].size() == 0)
            return false;
        if (matrix[matrix.size() - 1][matrix[0].size() - 1] < target)
            return false;
        if (matrix[0][0] > target)
            return false;

        int start = 0, end = matrix.size() - 1;
        int ref;
        int mid;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (matrix[mid][matrix[0].size() - 1] == target)
            {
                // cout << start << " " << mid << " " << end << endl;
                return true;
            }
            else if (matrix[mid][matrix[0].size() - 1] > target)
            {
                ref = mid;
                end = mid - 1;

                continue;
            }
            else if (matrix[mid][matrix[0].size() - 1] < target)
            {
                start = mid + 1;
                // mid = start + (start - end) / 2;
                // cout << start << " " << mid << " " << end << endl;
                continue;
            }
        }
        // cout << "mid is " << mid;
        int row = ref;
        start = 0;
        end = matrix[row].size() - 1;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (matrix[row][mid] == target)
            {
                // cout << start << " " << mid << " " << end << endl;
                return true;
            }
            else if (matrix[row][mid] > target)
            {
                end = mid - 1;
                // cout << start << " " << mid << " " << end << endl;
                continue;
            }
            else if (matrix[row][mid] < target)
            {
                start = mid + 1;
                // cout << start << " " << mid << " " << end << endl;
                continue;
            }
        }
        // cout << "mid is " << mid;
        return false;
    }
};