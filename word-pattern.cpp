#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

class BestMemorySolution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> map;
        string value = "";
        int start = 0;
        for (int i = 0; i < pattern.size(); i++)
        {
            // printf("%d  ", start);
            for (start; start < s.size(); start++)
            {
                if (s[start] != ' ')
                {
                    value += s[start];
                }
                else
                    break;
            }
            // printf("%s  ", value.c_str());
            if (map[pattern[i]] == "")
            {
                for (auto &n : map)
                {
                    if (n.second == value)
                        return false;
                }
                map[pattern[i]] = value;
            }
            else
            {
                if (map[pattern[i]] != value)
                {
                    return false;
                }
            }
            value = "";
            start += 1;
            // printf("%s", value.c_str());
        }
        // printf("%d %d", s.size(), 2);
        if (s.size() != start - 1)
            return false;
        return true;
    }
};

class MySolution
{
public:
    vector<string> returnSubstring(string s, char delimeter)
    {
        vector<string> substrings;
        size_t start = 0;
        size_t end = s.find(delimeter);
        do
        {
            end = s.find(delimeter, start);
            // cout << start << end << endl;
            substrings.push_back(s.substr(start, end - start));
            start = end + 1;

        } while (end != string::npos);
        return substrings;
    }
    bool checkMap(map<char, string> &charMap, string &s)
    {
        for (auto p : charMap)
        {
            if (p.second == s)
            {
                return true;
            }
        }
        return false;
    }

    bool wordPattern(string pattern, string s)
    {
        vector<string> substring = returnSubstring(s, ' ');
        // for (auto s : substring)
        //     cout << s << " ";
        // cout << endl;
        if (substring.size() != pattern.size())
            return false;
        map<char, string> charMap;
        int i = 0;
        for (char c : pattern)
        {
            // cout << " " << c << " " << i << " " << substring[i] << endl;
            if (charMap.count(c) > 0)
            {
                // cout << charMap[c] << endl;
                if (charMap[c] != substring[i])
                    return false;
            }
            else
            {
                if (checkMap(charMap, substring[i]))
                    return false;
                else
                    charMap[c] = substring[i];
            }
            i++;
        }
        // cout << "out";
        return true;
    }
};

class AlternateSolution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> map1;
        unordered_map<string, char> map2;
        vector<string> words;
        int len_s = s.size();
        int len_p = pattern.size();
        int start = 0;
        for (int i = 0; i < len_s; i++)
        {
            if (s[i] == ' ')
            {
                words.push_back(s.substr(start, i - start));
                start = i + 1;
            }
        }
        words.push_back(s.substr(start, len_s - start));
        int num_words = words.size();
        if (len_p != words.size())
            return false;

        for (int i = 0; i < num_words; i++)
        {
            if (!map1.count(pattern[i]) && !map2.count(words[i]))
            {
                map1[pattern[i]] = words[i];
                map2[words[i]] = pattern[i];
            }
            else if (map1.count(pattern[i]) && map2.count(words[i]) && map1[pattern[i]] == words[i] && map2[words[i]] == pattern[i])
                continue;
            else
                return false;
        }
        return true;
    }
};