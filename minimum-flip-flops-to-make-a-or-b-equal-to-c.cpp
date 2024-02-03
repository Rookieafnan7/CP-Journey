// Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
// Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.

// Example 1:

// Input: a = 2, b = 6, c = 5
// Output: 3
// Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)
// Example 2:

// Input: a = 4, b = 2, c = 7
// Output: 1
// Example 3:

// Input: a = 1, b = 2, c = 3
// Output: 0

// Constraints:

// 1 <= a <= 10^9
// 1 <= b <= 10^9
// 1 <= c <= 10^9
class BetterSolution
{
public:
    int minFlips(int a, int b, int c)
    {
        int totalCount = 0;
        while (a | b | c)
        {
            // Extract and examine the right-most bit
            int a_i = a & 1;
            int b_i = b & 1;
            int c_i = c & 1;
            if ((a_i | b_i) != c_i)
            {
                // Scenario: c: 1, a: 0, b: 0 -> one action,
                //           c: 0, a: 1, b: 1 -> two actions
                if (a_i & b_i)
                {
                    totalCount += 2;
                }
                else
                {
                    totalCount += 1;
                }
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return totalCount;
    }
};
class MySolution
{
public:
    int minFlips(int a, int b, int c)
    {
        int count = 0;
        for (int i = 0; i < 32; i++)
        {
            int bit = (c >> i) & 1;
            int bit1 = ((a >> i) & 1);
            int bit2 = ((b >> i) & 1);
            if (bit == 0)
            {
                if (bit1 && bit2)
                    count += 2;
                else if (bit1 || bit2)
                    count += 1;
            }
            else
            {
                if (!(bit1 || bit2))
                {
                    count += 1;
                }
            }
        }
        return count;
    }
};