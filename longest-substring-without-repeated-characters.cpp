// Given a string s, find the length of the longest
// substring
//  without repeating characters.

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.

// similar concept , sliding window, using arrays

class BestSolution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() < 2)
        {
            return s.size();
        }

        int result = 0;

        bool visited[256] = {false};

        int l = 0, r = 0;

        while (r < s.size())
        {
            if (visited[s[r]])
            {
                while (visited[s[r]])
                {
                    visited[s[l]] = false;
                    l++;
                }
            }

            visited[s[r]] = true;

            r++;

            result = std::max(result, r - l);
        }

        return result;
    }
};

// using the previous property similar to the question substring with concatenation of all words
class MySolution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() <= 1)
            return s.size();
        unordered_map<string, int> ref;
        int maxLen = 0;
        int left = 0, right = 1;
        bool flag = true;
        while (right <= s.size())
        {
            if (flag)
                ref[s.substr(right - 1, 1)]++;
            else
                ref[s.substr(left - 1, 1)]--;
            string sub = s.substr(right - 1, 1);
            if (ref[sub] > 1)
            {
                flag = false;
                left++;
            }
            else
            {
                maxLen = max(maxLen, right - left);
                right++;
                flag = true;
            }
        }
        return maxLen;
    }
};