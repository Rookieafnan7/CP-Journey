// https://leetcode.com/problems/bitwise-and-of-numbers-range/description/?envType=study-plan-v2&envId=top-interview-150
// Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

// Example 1:

// Input: left = 5, right = 7
// Output: 4
// Example 2:

// Input: left = 0, right = 0
// Output: 0
// Example 3:

// Input: left = 1, right = 2147483647
// Output: 0

// Constraints:

// 0 <= left <= right <= 231 - 1



//
class BestSolution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int c = 0;
        while (left != right)
        {
            left >>= 1;
            right >>= 1;
            c++;
        }
        return left << c;
    }
};

// O(log(min(left,right))) but needs a bit more space

class MySolution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        if (right == left)
            return right;
        if (right < left)
            return rangeBitwiseAnd(right, left);
        int out = 0;
        long prod = 1;
        int index = 0;
        while (prod <= right && prod <= left)
        {
            if (right - left <= prod)
                out |= ((right >> index) & (left >> index) & 1) << index;
            index++;
            prod *= 2;
        }
        return out;
    }
};
