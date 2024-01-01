// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character

// Example 1:

// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation:
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
// Example 2:

// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation:
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')

// Constraints:

// 0 <= word1.length, word2.length <= 500
// word1 and word2 consist of lowercase English letters.

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word2.size(), n = word1.size();
        if (n == 0)
            return m;
        if (m == 0)
            return n;

        int dp[m + 1][n + 1];
        dp[m][n] = 0;
        for (int i = 0; i < n; i++)
            dp[m][i] = n - i;
        for (int i = 0; i < m; i++)
            dp[i][n] = m - i;
        for (int i = m - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--)
                if (word2[i] == word1[j])
                    dp[i][j] = dp[i + 1][j + 1];
                else
                    dp[i][j] = 1 + min(dp[i + 1][j], min(dp[i + 1][j + 1], dp[i][j + 1]));
        return dp[0][0];
    }
};