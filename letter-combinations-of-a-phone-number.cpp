// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/?envType=study-plan-v2&envId=top-interview-150
//  Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]

// Constraints:

// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].
#include <vector>
#include <bits/stdc++.h>
// #include <vector>
#include <deque>
#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

class Solution
{
public:
    vector<char> returnChars(char &c)
    {
        // vector<char> temp;
        switch (c)
        {
        case '2':
            return vector<char>({'a', 'b', 'c'});
        case '3':
            return vector<char>({'d', 'e', 'f'});
        case '4':
            return vector<char>({'g', 'h', 'i'});
        case '5':
            return vector<char>({'j', 'k', 'l'});
        case '6':
            return vector<char>({'m', 'n', 'o'});
        case '7':
            return vector<char>({'p', 'q', 'r', 's'});
        case '8':
            return vector<char>({'t', 'u', 'v'});
        case '9':
            return vector<char>({'w', 'x', 'y', 'z'});
        }

        return vector<char>({});
    }

    vector<string> letterCombinations(string digits)
    {
        deque<string> q;
        vector<string> sol;
        if (digits.size() == 0)
            return sol;
        q.push_back("");
        for (int i = 0; i < digits.size(); i++)
        {
            int n = q.size();
            while (n--)
            {
                string t = q.front();
                vector<char> chars = returnChars(digits[i]);
                for (auto &c : chars)
                {
                    string temp = t + c;
                    q.push_back(temp);
                }
                q.pop_front();
            }
        }

        for (auto &s : q)
        {
            sol.push_back(s);
        }
        return sol;
    }
};