// https://leetcode.com/problems/house-robber/?envType=study-plan-v2&envId=top-interview-150
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 2:

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 400
#include <vector>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int size = nums.size();
        if (size == 0)
            return 0;
        if (size == 1)
            return nums[0];
        int store[size];
        store[0] = nums[0];
        store[1] = nums[1];
        if (size >= 3)
            store[2] = nums[2] + nums[0];
        for (int i = 3; i < size; i++)
        {
            store[i] = nums[i] + max(store[i - 2], store[i - 3]);
        }
        return max(store[size - 1], store[size - 2]);
    }
};