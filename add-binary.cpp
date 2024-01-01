// Given two binary strings a and b, return their sum as a binary string.

// Example 1:

// Input: a = "11", b = "1"
// Output: "100"
// Example 2:

// Input: a = "1010", b = "1011"
// Output: "10101"

// Constraints:

// 1 <= a.length, b.length <= 104
// a and b consist only of '0' or '1' characters.
// Each string does not contain leading zeros except for the zero itself.

class BestSolution
{
public:
    string addBinary(string a, string b)
    {
        string ans;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        while (i >= 0 || j >= 0 || carry)
        {
            if (i >= 0)
            {
                carry += a[i--] - '0';
            }
            if (j >= 0)
            {
                carry += b[j--] - '0';
            }
            ans += carry % 2 + '0';
            carry /= 2;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};

class SlowSolution
{
public:
    string addBinary(string a, string b)
    {
        string res = "";
        int carry = 0;
        int minSize = min((int)(a.size()), (int)(b.size()));
        for (int i = 0; i < minSize; i++)
        {
            int bit1 = a[a.size() - 1 - i] - '0';
            int bit2 = b[b.size() - 1 - i] - '0';
            res = to_string((carry + bit1 + bit2) % 2) + res;
            if (sum > 1)
                carry = 1;
            else
                carry = 0;
        }
        if (a.size() > b.size())
        {
            for (int i = a.size() - 1 - minSize; i >= 0; i--)
            {
                int bit = a[i] - '0';
                if (bit && carry)
                {
                    res = "0" + res;
                    carry = 1;
                }
                else if (bit || carry)
                {
                    res = "1" + res;
                    carry = 0;
                }
                else
                    res = "0" + res;
            }
        }
        else
        {
            for (int i = b.size() - 1 - minSize; i >= 0; i--)
            {
                int bit = b[i] - '0';
                if (bit && carry)
                {
                    res = "0" + res;
                    carry = 1;
                }
                else if (bit || carry)
                {
                    res = "1" + res;
                    carry = 0;
                }
                else
                    res = "0" + res;
            }
        }
        if (carry)
            res = "1" + res;
        return res;
    }
};