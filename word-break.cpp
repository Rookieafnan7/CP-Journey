// https://leetcode.com/problems/word-break/description/?envType=study-plan-v2&envId=top-interview-150
//  Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:

// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false

// Constraints:

// 1 <= s.length <= 300
// 1 <= wordDict.length <= 1000
// 1 <= wordDict[i].length <= 20
// s and wordDict[i] consist of only lowercase English letters.
// All the strings of wordDict are unique.

#include <unordered_map>
#include <string>
#include <vector>
#include <set>
using namespace std;

class GoodSolution1
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {

        bool dp[s.size() + 1];
        for (int i = 0; i < s.size() + 1; i++)
            dp[i] = false;
        dp[s.size()] = true;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (auto &t : wordDict)
            {
                if (i + t.size() <= s.size())
                {
                    string sub = s.substr(i, t.size());
                    if (sub == t)
                        dp[i] = dp[i + t.size()];
                }
                if (dp[i])
                    break;
            }
        }
        return dp[0];
    }
};

class GoodSolution2
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<string> st;
        for (auto it : wordDict)
            st.insert(it);
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j])
                {
                    string temp = s.substr(j, i - j);
                    if (st.find(temp) != st.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};

class MyBadSolution
{
public:
    bool helper(unordered_map<string, bool> &m, string &s, int start, int len)
    {
        if (start > s.size() - 1)
            return true;
        if (start + len - 1 > s.size() - 1)
            return false;
        string sub = s.substr(start, len);
        // cout<<"sub "<<sub<<" start "<<start<<" len "<<len<<endl;
        if (m[sub])
        {
            // cout<<"sub click "<<sub<<endl;
            return helper(m, s, start + len, 1) || helper(m, s, start, len + 1);
        }
        else
            return helper(m, s, start, len + 1);
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        if (s.size() == 0)
            return false;
        if (wordDict.size() == 0)
            return false;
        unordered_map<string, bool> m;
        for (auto &word : wordDict)
            m[word] = true;
        int size = s.size();

        return helper(m, s, 0, 1);
    }
};