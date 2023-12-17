// https://leetcode.com/problems/valid-anagram/description/?envType=study-plan-v2&envId=top-interview-150
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

//                                                                     An Anagram is a word or
//                                                                     phrase formed by rearranging the letters of a different word or phrase,
//     typically using all the original letters exactly once.

//     Example 1 :

//     Input : s = "anagram",
//             t = "nagaram" Output : true Example 2 :

//     Input : s = "rat",
//             t = "car" Output : false

//                                Constraints :

//                                1 <= s.length,
//             t.length <= 5 * 104 s and t consist of lowercase English letters.
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> m;
        for (auto &c : s)
        {
            // if(m.find(c)!=m.end())
            m[c]++;
            // else m[c] = 1;
        }
        for (auto &c : t)
        {
            // if(m.find(c)!=m.end()){
            if (m[c]-- > 0)
                continue;
            else
                return false;
            // }else return false;
        }
        return true;
    }
};