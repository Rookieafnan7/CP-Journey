// Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

// Example 1:

// Input: s = "abciiidef", k = 3
// Output: 3
// Explanation: The substring "iii" contains 3 vowel letters.
// Example 2:

// Input: s = "aeiou", k = 2
// Output: 2
// Explanation: Any substring of length 2 contains 2 vowels.
// Example 3:

// Input: s = "leetcode", k = 3
// Output: 2
// Explanation: "lee", "eet" and "ode" contain 2 vowels.

// Constraints:

// 1 <= s.length <= 105
// s consists of lowercase English letters.
// 1 <= k <= s.length

auto init_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int maxVowels = 0, currentVowels = 0;
        for (int i = 0; i < k; ++i)
        {
            if (isVowel(s[i]))
                currentVowels++;
        }
        maxVowels = currentVowels;

        for (int i = k; i < s.length(); ++i)
        {
            if (isVowel(s[i]))
                currentVowels++;
            if (isVowel(s[i - k]))
                currentVowels--;
            maxVowels = max(maxVowels, currentVowels);
        }

        return maxVowels;
    }

private:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        // || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};