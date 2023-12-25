// https://leetcode.com/problems/basic-calculator/description/?envType=study-plan-v2&envId=top-interview-150
// https://www.youtube.com/watch?v=081AqOuasw0
// Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

// Example 1:

// Input: s = "1 + 1"
// Output: 2
// Example 2:

// Input: s = " 2-1 + 2 "
// Output: 3
// Example 3:

// Input: s = "(1+(4+5+2)-3)+(6+8)"
// Output: 23

// Constraints:

// 1 <= s.length <= 3 * 105
// s consists of digits, '+', '-', '(', ')', and ' '.
// s represents a valid expression.
// '+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
// '-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
// There will be no two consecutive operators in the input.
// Every number and running calculation will fit in a signed 32-bit integer.

class BestSolution
{
public:
    int calculate(string s)
    {
        long long int sum = 0;
        int sign = 1;
        stack<pair<int, int>> st;

        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                long long int num = 0;
                while (i < s.size() && isdigit(s[i]))
                {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                sum += num * sign;
                sign = 1;
            }
            else if (s[i] == '(')
            {
                st.push({sum, sign});
                sum = 0;
                sign = 1;
            }
            else if (s[i] == ')')
            {
                sum = st.top().first + (st.top().second * sum);
                st.pop();
            }
            else if (s[i] == '-')
            {
                sign = -1 * sign;
            }
        }
        return sum;
    }
};

class MySolution
{
public:
    int calculate(string s)
    {
        stack<int> ss;
        int sign = 1, sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
                continue;
            if (s[i] >= '0' && s[i] <= '9')
            {
                int num = 0;
                while (i < s.size() && s[i] >= '0' && s[i] <= '9')
                    num = num * 10 + (int)(s[i++] - '0');
                sum += num * sign;
                i--;
            }
            else if (s[i] == '+')
                sign = 1;
            else if (s[i] == '-')
                sign = -1;
            else if (s[i] == '(')
            {
                ss.push(sum);
                ss.push(sign);
                sum = 0;
                sign = 1;
            }
            else if (s[i] == ')')
            {
                sum = ss.top() * sum;
                ss.pop();
                sum += ss.top();
                ss.pop();
            }
        }
        return sum;
    }
};