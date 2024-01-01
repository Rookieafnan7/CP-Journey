// https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150
// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

// Constraints:

// 1 <= nums.length <= 104
// 0 <= nums[i] <= 105
class BestSolution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;
        if (nums[0] == 0)
            return false;
        int goal = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (i + nums[i] >= goal)
            {
                goal = i;
            }
        }
        return (goal == 0);
    }
};
class BadTOGoodSolution
{
public:
    bool canJump(vector<int> &nums)
    {
        // vector<int> s(nums.size(), 0);
        // queue<int> q;
        // int target = nums.size() - 1;
        // q.push(0);
        // while(!q.empty()){
        //     int n = q.size();
        //     while(n--){
        //         int topI = q.front();
        //         q.pop();
        //         if(s[topI]) continue;
        //         if(topI == target) return true;
        //         else s[topI]++;
        //         for( int i = topI + 1; i <= min(topI + nums[topI], target); i++)
        //             if(s[i]) continue;
        //             else q.push(i);
        //     }
        // }
        // return false;

        // vector<bool> dp(nums.size(), false);
        // dp[nums.size() - 1] = true;
        // for(int i = nums.size() - 2; i>=0; i--){
        //     int flag = false;
        //     for(int j = i + 1;!flag && j <= min(nums[i] + i, (int)(nums.size()-1)); j++)
        //         if(dp[j]) flag = true;
        //     dp[i] = flag;
        // }
        // return dp[0];

        int n = nums.size(), reach = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > reach || reach >= n - 1)
                break;
            reach = max(reach, i + nums[i]);
        }
        return reach >= n - 1;
    }
};