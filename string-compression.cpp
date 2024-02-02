// Given an array of characters chars, compress it using the following algorithm:

// Begin with an empty string s. For each group of consecutive repeating characters in chars:

// If the group's length is 1, append the character to s.
// Otherwise, append the character followed by the group's length.
// The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

// After you are done modifying the input array, return the new length of the array.

// You must write an algorithm that uses only constant extra space.

// Example 1:

// Input: chars = ["a","a","b","b","c","c","c"]
// Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
// Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
// Example 2:

// Input: chars = ["a"]
// Output: Return 1, and the first character of the input array should be: ["a"]
// Explanation: The only group is "a", which remains uncompressed since it's a single character.
// Example 3:

// Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
// Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
// Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".

// Constraints:

// 1 <= chars.length <= 2000
// chars[i] is a lowercase English letter, uppercase English letter, digit, or symbol.
class BetterSolution
{
public:
    int compress(vector<char> &chars)
    {
        if (chars.size() == 1)
            return 1;

        char currChar = chars[0];
        int counter = 1;
        int j = 0;

        for (int i = j + 1; i < chars.size(); i++)
        {
            if (currChar == chars[i])
            {
                counter++;
                continue;
            }

            chars[j++] = currChar;
            currChar = chars[i];
            if (counter > 1)
            {
                string str = to_string(counter);
                for (int k = 0; k < str.size() && j < chars.size(); k++)
                {
                    chars[j++] = str[k];
                }
                counter = 1;
            }
        }

        chars[j++] = currChar;
        if (counter > 1)
        {
            string str = to_string(counter);
            for (int k = 0; k < str.size() & j < chars.size(); k++)
            {
                chars[j++] = str[k];
            }
        }

        return j;
    }
};

//                                             *   currChar
//"a","b","b","b","b","b","b","b","b","b","b","b","b"

class MySolution
{
public:
    int compress(vector<char> &chars)
    {
        string res;
        char save = chars[0];
        int start = 0;
        int i = 1;
        for (i = 1; i < chars.size(); i++)
        {
            if (save != chars[i])
            {
                res += save;
                save = chars[i];
                int size = i - start;
                if (size != 1)
                    res += to_string(i - start);
                start = i;
            }
            else
                continue;
        }
        res += save;
        if (i - start > 1)
            res += to_string(i - start);
        chars.clear();
        for (auto &c : res)
            chars.push_back(c);
        return res.size();
    }
};