// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9.
// X can be placed before L (50) and C (100) to make 40 and 90.
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given an integer, convert it to a roman numeral.

// Example 1:

// Input: num = 3
// Output: "III"
// Explanation: 3 is represented as 3 ones.
// Example 2:

// Input: num = 58
// Output: "LVIII"
// Explanation: L = 50, V = 5, III = 3.
// Example 3:

// Input: num = 1994
// Output: "MCMXCIV"
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

// Constraints:

// 1 <= num <= 3999

class BestSolution
{
public:
    string intToRoman(int num)
    {
        string ronamNum = "";

        while (num > 0)
        {
            if (num >= 1000)
            {
                ronamNum += "M";
                num -= 1000;
            }
            else if (num >= 500)
            {
                if (num >= 900)
                {
                    ronamNum += "CM";
                    num -= 900;
                }
                else
                {
                    ronamNum += "D";
                    num -= 500;
                }
            }
            else if (num >= 100)
            {
                if (num >= 400)
                {
                    ronamNum += "CD";
                    num -= 400;
                }
                else
                {
                    ronamNum += "C";
                    num -= 100;
                }
            }
            else if (num >= 50)
            {
                if (num >= 90)
                {
                    ronamNum += "XC";
                    num -= 90;
                }
                else
                {
                    ronamNum += "L";
                    num -= 50;
                }
            }
            else if (num >= 10)
            {
                if (num >= 40)
                {
                    ronamNum += "XL";
                    num -= 40;
                }
                else
                {
                    ronamNum += "X";
                    num -= 10;
                }
            }
            else if (num >= 5)
            {
                if (num >= 9)
                {
                    ronamNum += "IX";
                    num -= 9;
                }
                else
                {
                    ronamNum += "V";
                    num -= 5;
                }
            }
            else if (num >= 1)
            {
                if (num >= 4)
                {
                    ronamNum += "IV";
                    num -= 4;
                }
                else
                {
                    ronamNum += "I";
                    num -= 1;
                }
            }
        }

        return ronamNum;
    }
};

class MySolution
{
public:
    string intToRoman(int num)
    {
        long prod = 10, sum = 0;
        string res = "";
        stack<int> v;
        while (prod / 10 <= num)
        {
            int val = (num % prod - sum);
            sum += val;
            prod *= 10;
            if (val != 0)
                v.push(val);
        }
        while (!v.empty())
        {
            int focus = v.top();
            v.pop();
            if (focus >= 1000)
            {
                int num = focus / 1000;
                for (int i = 0; i < num; i++)
                    res += "M";
            }
            else if (focus == 900)
                res += "CM";
            else if (focus >= 500)
            {
                int num = (focus - 500) / 100;
                res += "D";
                for (int i = 0; i < num; i++)
                    res += "C";
            }
            else if (focus == 400)
                res += "CD";
            else if (focus >= 100)
            {
                int num = focus / 100;
                for (int i = 0; i < num; i++)
                    res += "C";
            }
            else if (focus == 90)
                res += "XC";
            else if (focus >= 50)
            {
                int num = (focus - 50) / 10;
                res += "L";
                for (int i = 0; i < num; i++)
                    res += "X";
            }
            else if (focus == 40)
                res += "XL";
            else if (focus >= 10)
            {
                int num = focus / 10;
                for (int i = 0; i < num; i++)
                    res += "X";
            }
            else if (focus == 9)
                res += "IX";
            else if (focus >= 5)
            {
                int num = (focus - 5);
                res += "V";
                for (int i = 0; i < num; i++)
                    res += "I";
            }
            else if (focus == 4)
                res += "IV";
            else if (focus >= 1)
            {
                int num = focus;
                for (int i = 0; i < num; i++)
                    res += "I";
            }
        }
        return res;
    }
};