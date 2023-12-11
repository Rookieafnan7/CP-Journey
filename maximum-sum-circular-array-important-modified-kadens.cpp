//https://leetcode.com/problems/maximum-sum-circular-subarray/description/?envType=study-plan-v2&envId=top-interview-150

// Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

// A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

// A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

// Example 1:

// Input: nums = [1,-2,3,-2]
// Output: 3
// Explanation: Subarray [3] has maximum sum 3.
// Example 2:

// Input: nums = [5,-3,5]
// Output: 10
// Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
// Example 3:

// Input: nums = [-3,-2,-3]
// Output: -2
// Explanation: Subarray [-2] has maximum sum -2.
 

// Constraints:

// n == nums.length
// 1 <= n <= 3 * 104
// -3 * 104 <= nums[i] <= 3 * 104



#include<vector>
#include<bits/stdc++.h>
using namespace std;


class BestSolution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total = 0, maxSum = A[0], curMax = 0, minSum = A[0], curMin = 0;
        for (int& a : A) {
            curMax = max(curMax + a, a);
            maxSum = max(maxSum, curMax);

            curMin = min(curMin + a, a);
            minSum = min(minSum, curMin);
            
            total += a;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};
//yet to be fully understood
class AlternativeSolution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total = 0, maxSum = A[0], curMax = 0, minSum = A[0], curMin = 0;
        for (int& a : A) {
            curMax = max(curMax + a, a);
            maxSum = max(maxSum, curMax);

            curMin = min(curMin + a, a);
            minSum = min(minSum, curMin);
            
            total += a;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};


class MySolution {
public:
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_sum_carry = 0,max_so_far = INT_MIN;
        int min_sum_carry = 0,min_so_far = INT_MAX;
        int maxi = 0;
        for(int i = 0; i < nums.size(); i++){
            maxi+=nums[i];
            min_sum_carry+=nums[i];
            max_sum_carry+=nums[i];
            if(max_sum_carry>max_so_far)
                max_so_far = max_sum_carry;
            if(min_sum_carry<min_so_far)
                min_so_far = min_sum_carry;
            if(max_sum_carry<0)
                max_sum_carry = 0;
            if(min_sum_carry>0)
                min_sum_carry = 0;
        }
        // cout<<max_so_far<<" "<<min_so_far;

        return max_so_far>0?max(max_so_far,maxi-min_so_far):max_so_far;
    }
};