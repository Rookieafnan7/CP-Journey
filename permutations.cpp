// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]

// Constraints:

// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// All the integers of nums are unique.
class Solution
{
public:
    void helper1(vector<vector<int>> &res, vector<int> &nums, vector<int> carry, int look[])
    {
        if (carry.size() == nums.size())
            res.push_back(carry);
        else
            for (int i = 0; i < nums.size(); i++)
                if (look[i])
                    continue;
                else
                {
                    look[i] = 1;
                    carry.push_back(nums[i]);
                    helper1(res, nums, carry, look);
                    look[i] = 0;
                    carry.pop_back();
                }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        if (nums.size() == 0)
            return vector<vector<int>>();
        int look[6] = {};
        vector<vector<int>> res;
        helper1(res, nums, vector<int>(), look);
        return res;
    }
};