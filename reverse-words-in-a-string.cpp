// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.

// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
// Example 3:

// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

// Constraints:

// 1 <= s.length <= 104
// s contains English letters (upper-case and lower-case), digits, and spaces ' '.
// There is at least one word in s.

// Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?

class BestSolution
{
public:
    void reverse(string &s)
    {
        int start = 0, end = s.length() - 1;
        while (start < end)
        {

            swap(s[start++], s[end--]);
        }
    }

    string reverseWords(string s)
    {
        string result;
        int i = 0;
        while (s[i] != '\0')
        {
            string word;
            while (s[i] == ' ')
                i++; // leading whitespaces

            while (s[i] != ' ' && s[i] != '\0')
            {
                word += s[i];
                i++;
            }
            reverse(word);
            result.append(word);

            while (s[i] == ' ')
                i++; // trailing whitespaces

            if (s[i] == '\0')
                break;
            else
                result += ' ';
        }

        reverse(result);

        return result;
    }
};

class BadSolution
{
public:
    string reverseWords(string s)
    {
        while (s.size() > 0 && s[0] == ' ')
            s = s.substr(1, s.size() - 1);
        while (s.size() > 0 && s[s.size() - 1] == ' ')
            s = s.substr(0, s.size() - 1);
        for (int i = 1; i < s.size();)
            if (s[i - 1] == ' ' && s[i] == ' ')
                s = s.substr(0, i) + s.substr(i + 1);
            else
                i++;
        reverse(s.begin(), s.end());
        int start, end;
        start = end = 0;
        while (end <= s.size() - 1)
            if (s[end] != ' ')
                end++;
            else
            {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
                end = start;
            }
        reverse(s.begin() + start, s.end());
        return s;
    }
};