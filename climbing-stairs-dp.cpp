// https://leetcode.com/problems/climbing-stairs/description/?envType=study-plan-v2&envId=top-interview-150
// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

// Constraints:

// 1 <= n <= 45

#include <vector>
#include <unordered_map>
using namespace std;

// Bottom Up Strategy, tabularization
class MySolution
{
public:
    int climbStairs(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int store[n + 1];
        store[0] = 1;
        store[1] = 1;
        for (int i = 2; i < n + 1; i++)
        {
            store[i] = store[i - 1] + store[i - 2];
        }
        return store[n];
    }
};

// Bottom up strategy, memoization
class AltSolution
{
public:
    int climbStairs(int n, unordered_map<int, int> &memo)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }
        if (memo.find(n) == memo.end())
        {
            memo[n] = climbStairs(n - 1, memo) + climbStairs(n - 2, memo);
        }
        return memo[n];
    }

    int climbStairs(int n)
    {
        unordered_map<int, int> memo;
        return climbStairs(n, memo);
    }
};