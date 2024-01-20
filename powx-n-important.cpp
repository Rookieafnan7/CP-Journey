// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

// Example 1:

// Input: x = 2.00000, n = 10
// Output: 1024.00000
// Example 2:

// Input: x = 2.10000, n = 3
// Output: 9.26100
// Example 3:

// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25

// Constraints:

// -100.0 < x < 100.0
// -231 <= n <= 231-1
// n is an integer.
// Either x is not zero or n > 0.
// -104 <= xn <= 104

// In order to improve efficiency we will opt for Binary Exponentiation using which we can calculate xn using O log2(N) multiplications.

// Basic Idea is to divide the work using binary representation of exponents
// i.e. is to keep multiplying pow with x, if the bit is odd, and multiplying x with itself until we get 0
// We will use very 1st example of 1st Approach i.e.
// x = 7, n = 11 and pow = 1
// Here, we have to calculate 711
// Binary of n i.e. (11)10 is (1011)2
// 1   0   1   1
// 23  22  21  20   <-- Corresponding place values of each bit

// OR we can also write this as
// 1 0 1 1
// 8 4 2 1 <-- Corresponding place values of each bit

// Now, 78 × 72 × 71 == 711 as 7(8 + 2 + 1) == 711
// NOTE: We have not considered 74 in this case as the 4th place bit is OFF

// So, 78 × 72 × 71 == 5764801 × 49 × 7 == 1977326743 <-- Desired Output
// Now, applying logic keeping this concept in mind



class BestSolution
{
public:
    double pow = 1;
    while (n != 0)
    {
        if ((n & 1) != 0) // equivalent to if((n % 2) != 0) i.e. multiply only when the number is odd
            pow *= x;

        x *= x;
        n >> >= 1; // equivalent to n = n / 2; i.e. keep dividing the number by 2
    }
}

class BadSolution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0 || x == 1)
            return 1;
        if (x == 0)
            return 0;
        if (x == -1 && n % 2 == 0)
            return 1;
        if (x == -1 && n % 2 != 0)
            return -1;
        int count = abs(n);
        double res = 1;
        if (n < 0)
            for (int i = 0; i < count; i++)
                res *= 1 / x;
        else
            for (int i = 0; i < count; i++)
                res *= x;
        return res;
    }
};