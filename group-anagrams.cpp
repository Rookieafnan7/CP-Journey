// https://leetcode.com/problems/group-anagrams/?envType=study-plan-v2&envId=top-interview-150
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Example 2:

// Input: strs = [""]
// Output: [[""]]
// Example 3:

// Input: strs = ["a"]
// Output: [["a"]]

// Constraints:

// 1 <= strs.length <= 104
// 0 <= strs[i].length <= 100
// strs[i] consists of lowercase English letters.

#include <vector>
#include <string>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (auto it : strs)
        {
            string tmp = it;
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(it);
        }
        vector<vector<string>> ans;
        for (auto it : mp)
            ans.push_back(it.second);
        return ans;
    }
};