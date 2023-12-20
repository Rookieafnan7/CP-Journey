// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Example 3:

// Input: coins = [1], amount = 0
// Output: 0

// Constraints:

// 1 <= coins.length <= 12
// 1 <= coins[i] <= 231 - 1
// 0 <= amount <= 104
#include <vector>
#include <climits>
using namespace std;


class MyProudSolution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int dp[amount + 1];
        for (int i = 0; i < amount + 1; i++)
            dp[i] = INT_MAX;
        dp[0] = 0;
        // int min = -1;
        for (int i = 1; i < amount + 1; i++)
        {
            for (auto &coin : coins)
            {
                if (i - coin >= 0 && dp[i - coin] != INT_MAX)
                {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        if (dp[amount] == INT_MAX)
            return -1;
        else
            return dp[amount];
    }
};