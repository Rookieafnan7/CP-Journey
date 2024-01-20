// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// Example 3:

// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.

// Constraints:

// 1 <= s.length <= 2 * 105
// s consists only of printable ASCII characters.
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string f;
        for (auto &c : s)
        {
            if (c >= 'A' && c <= 'Z')
            {
                int temp = c - 'A';
                f += (char)('a' + temp);
            }
            else if (c >= 'a' && c <= 'z')
                f += c;
            else if (c >= '0' && c <= '9')
                f += c;
        }
        // cout<<f<<endl;
        int size = f.size();
        if (size == 0)
            return true;
        for (int i = 0; i <= (size - 1) / 2; i++)
        {
            if (f[i] != f[size - 1 - i])
                return false;
            else
                continue;
        }
        return true;
    }
};