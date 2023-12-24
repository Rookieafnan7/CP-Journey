// https://leetcode.com/problems/longest-common-prefix/description/?envType=study-plan-v2&envId=top-interview-150
// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// sort lexicographically first
// since if there is some prefix the one that ends early would come earlier
// so no need to worry about that

class BestSolution
{
public:
    string longestCommonPrefix(vector<string> &v)
    {
        string ans = "";
        sort(v.begin(), v.end());
        int n = v.size();
        string first = v[0], last = v[n - 1];
        for (int i = 0; i < min(first.size(), last.size()); i++)
        {
            if (first[i] != last[i])
            {
                return ans;
            }
            ans += first[i];
        }
        return ans;
    }
};

class MySolution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
            return "";
        int minLen = INT_MAX;
        for (auto s : strs)
            minLen = min((unsigned long)minLen, s.size());
        string save = "";
        // cout<<"minlen "<< minLen;
        for (int i = 0; i < minLen; i++)
        {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[j][i] == c)
                    continue;
                else
                    return save;
            }
            save += c;
        }
        return save;
    }
};