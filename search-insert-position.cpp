// https://leetcode.com/problems/search-insert-position/?envType=study-plan-v2&envId=top-interview-150
// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2
// Example 2:

// Input: nums = [1,3,5,6], target = 2
// Output: 1
// Example 3:

// Input: nums = [1,3,5,6], target = 7
// Output: 4

// Constraints:

// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums contains distinct values sorted in ascending order.
// -104 <= target <= 104

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int ref = -1;
        if (target > nums[right])
            return right + 1;
        if (target < nums[left])
            return 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
            {
                ref = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return ref + 1;
    }
};