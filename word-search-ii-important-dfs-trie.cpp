// https://leetcode.com/problems/word-search-ii/?envType=study-plan-v2&envId=top-interview-150
// https://www.youtube.com/watch?v=asbcE9mZz_U

// Given an m x n board of characters and a list of strings words, return all words on the board.

// Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

// Example 1:

// Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
// Output: ["eat","oath"]
// Example 2:

// Input: board = [["a","b"],["c","d"]], words = ["abcb"]
// Output: []

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 12
// board[i][j] is a lowercase English letter.
// 1 <= words.length <= 3 * 104
// 1 <= words[i].length <= 10
// words[i] consists of lowercase English letters.
// All the strings of words are unique.
#include <vector>
#include <cstddef>
#include <string>
#include <set>
#include <unordered_set>
#include <iostream>
using namespace std;

class BestSolution
{
    struct TrieNode
    {
        TrieNode *children[26];
        string word;
        bool canDelete;

        TrieNode() : word(""), canDelete(false)
        {
            for (int i = 0; i < 26; i++)
            {
                children[i] = nullptr;
            }
        }
    };

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        TrieNode *root = buildTrie(words);
        vector<string> result;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (root->canDelete)
                    return result;
                dfs(board, i, j, root, result);
            }
        }
        return result;
    }

    /** Inserts a word into the trie. */
    TrieNode *buildTrie(vector<string> &words)
    {
        TrieNode *root = new TrieNode();
        for (int j = 0; j < words.size(); j++)
        {
            string word = words[j];
            TrieNode *curr = root;
            for (int i = 0; i < word.length(); i++)
            {
                char c = word[i] - 'a';
                if (curr->children[c] == nullptr)
                {
                    curr->children[c] = new TrieNode();
                }
                curr = curr->children[c];
            }
            curr->word = word;
        }
        return root;
    }

    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *p, vector<string> &result)
    {
        char c = board[i][j];
        if (c == '#' || !p->children[c - 'a'])
            return;
        if (p->children[c - 'a']->canDelete)
        {
            p->children[c - 'a'] = nullptr;
            bool noChild = true;
            for (int i = 0; i < 26; i++)
            {
                if (p->children[i] != nullptr)
                {
                    noChild = false;
                }
            }
            if (noChild)
            {
                p->canDelete = true;
            }
            return;
        }
        p = p->children[c - 'a'];
        if (p->word.size() > 0)
        {
            result.push_back(p->word);
            p->word = "";
            bool noChild = true;
            for (int i = 0; i < 26; i++)
            {
                if (p->children[i] != nullptr)
                {
                    noChild = false;
                }
            }
            if (noChild)
            {
                p->canDelete = true;
                return;
            }
        }

        board[i][j] = '#';
        if (i > 0)
            dfs(board, i - 1, j, p, result);
        if (j > 0)
            dfs(board, i, j - 1, p, result);
        if (i < board.size() - 1)
            dfs(board, i + 1, j, p, result);
        if (j < board[0].size() - 1)
            dfs(board, i, j + 1, p, result);
        board[i][j] = c;
    }
};

class MySolution
{
    class Node
    {
    public:
        Node *link[26];
        bool flag;
        Node()
        {
            flag = false;
            for (auto &ptr : link)
            {
                ptr = nullptr;
            }
        }
        bool isPresent(char c)
        {
            return (link[c - 'a'] != NULL);
        }
        void putNode(char c, Node *node)
        {
            link[c - 'a'] = node;
        }
        Node *getNode(char c)
        {
            return link[c - 'a'];
        }
    };

public:
    Node *root;
    MySolution()
    {
        root = new Node();
    }

    void insertWord(string &s)
    {
        // cout<<"insert string "<<s<<endl;
        Node *node = root;
        int index = 0;
        // cout<<"string "<<s<<endl;
        while (index < s.size())
        {

            if (node->isPresent(s[index]))
            {
                // cout<<"old "<<s[index]<<endl;
                node = node->getNode(s[index]);
            }
            else
            {
                // cout<<"new "<<s[index]<<endl;
                node->putNode(s[index], new Node());
                node = node->getNode(s[index]);
            }
            index++;
        }
        node->flag = true;
    }

    void check(vector<vector<char>> &board, int i, int j, Node *node, vector<string> &foundWords, string s)
    {

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '0')
            return;
        if (!node->link[board[i][j] - 'a'])
            return;

        // traversed.insert(make_pair(i, j));
        s += board[i][j];
        node = node->link[board[i][j] - 'a'];
        if (node->flag)
        {
            // cout << "found " << s << endl;
            foundWords.push_back(s);
            node->flag = false;
        }
        char temp = board[i][j];
        board[i][j] = '0';
        if (i > 0)
            check(board, i - 1, j, node, foundWords, s);
        if (i < board.size() - 1)
            check(board, i + 1, j, node, foundWords, s);
        if (j > 0)
            check(board, i, j - 1, node, foundWords, s);
        if (j < board[0].size() - 1)
            ;
        check(board, i, j + 1, node, foundWords, s);
        board[i][j] = temp;
        // traversed.erase(make_pair(i, j));
        return;
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        ios::sync_with_stdio(false);
        vector<string> foundWords;
        // vector<string> foundWordsArr;
        int wordsToFind = words.size();
        for (auto &s : words)
            insertWord(s);
        // cout << "insertion done" << endl;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                // cout<<i<<j<<endl;

                // set<pair<int, int>> traversed;
                if (root->link[board[i][j] - 'a'])
                    check(board, i, j, root, foundWords, "");
            }
        }

        return foundWords;
    }
};