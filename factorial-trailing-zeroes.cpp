// Given an integer n, return the number of trailing zeroes in n!.

// Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

// Example 1:

// Input: n = 3
// Output: 0
// Explanation: 3! = 6, no trailing zero.
// Example 2:

// Input: n = 5
// Output: 1
// Explanation: 5! = 120, one trailing zero.
// Example 3:

// Input: n = 0
// Output: 0

// Constraints:

// 0 <= n <= 104

// Follow up: Could you write a solution that works in logarithmic time complexity?

// say take n as 125
// out of 125 numbers how many of them divisible by 5
// you get 25 numbers like 5 10 15 20 25    ....  125 in sequence
// out of these 25 numbers how many of them are divisible by 5 again
// 25 50 75 125   5 numbers
// out of these 5 how many of them are divisible by 5
// 125 1 number
// hence 25 divisible by 5, 5 by 25 and 1 by 125 (not exclusive)
// hence total 31

class BestSolution
{
public:
    int trailingZeroes(int n)
    {
        int count = 0;
        while (n > 0)
        {
            n /= 5;
            count += n;
        }
        return count;
    }
};
class MySolution
{
public:
    int trailingZeroes(int n)
    {
        if (n < 5)
            return 0;
        int fives = 0, sum = 5;
        while (n >= sum)
        {
            int temp = sum;
            while (temp % 5 == 0 && temp > 0)
            {
                fives++;
                temp /= 5;
            }
            sum += 5;
        }
        return fives;
    }
};