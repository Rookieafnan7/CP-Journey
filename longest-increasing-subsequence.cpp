// https://leetcode.com/problems/longest-increasing-subsequence/description/?envType=study-plan-v2&envId=top-interview-150

// Given an integer array nums, return the length of the longest strictly increasing
// subsequence
// .

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1

// Constraints:

// 1 <= nums.length <= 2500
// -104 <= nums[i] <= 104

#include <vector>
#include <bits/stdc++.h>
using namespace std;

// using lower bound
class BestSolution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        // vector<int> lis(n,1);
        vector<int> temp;
        int maxi = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            int index = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            if (index == temp.size())
                temp.push_back(nums[i]);
            else
                temp[index] = nums[i];
        }
        return temp.size();
        // return maxi;
    }
};

// using straighforward DP
class MySolution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int size = nums.size();
        int dp[size];
        for (int i = 0; i < size; i++)
            dp[i] = 0;
        int maxLen = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int local_max = 1;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] > nums[i])
                {
                    local_max = max(local_max, 1 + dp[j]);
                }
            }
            dp[i] = local_max;
            maxLen = max(maxLen, local_max);
        }
        return maxLen;
    }
};