// https://leetcode.com/problems/design-add-and-search-words-data-structure/description/?envType=study-plan-v2&envId=top-interview-150

// Design a data structure that supports adding new words and finding if a string matches any previously added string.

// Implement the WordDictionary class:

// WordDictionary() Initializes the object.
// void addWord(word) Adds word to the data structure, it can be matched later.
// bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.

// Example:

// Input
// ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
// [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
// Output
// [null,null,null,null,false,true,true,true]

// Explanation
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("bad");
// wordDictionary.addWord("dad");
// wordDictionary.addWord("mad");
// wordDictionary.search("pad"); // return False
// wordDictionary.search("bad"); // return True
// wordDictionary.search(".ad"); // return True
// wordDictionary.search("b.."); // return True

// Constraints:

// 1 <= word.length <= 25
// word in addWord consists of lowercase English letters.
// word in search consist of '.' or lowercase English letters.
// There will be at most 2 dots in word for search queries.
// At most 104 calls will be made to addWord and search.

#include <string>
using namespace std;

class WordDictionary
{
public:
    class Node
    {
    public:
        Node *link[26];
        bool flag;
        Node()
        {
            flag = false;
            for (int i = 0; i < 26; i++)
                link[i] = nullptr;
        }
        bool containsChar(char c)
        {

            return (link[c - 'a'] != nullptr);
        }
        Node *getNode(char c)
        {

            return link[c - 'a'];
        }
        void put(char c, Node *node)
        {

            link[c - 'a'] = node;
        }
    };

public:
    Node *root;
    WordDictionary()
    {
        root = new Node();
    }
    void addWord(string s)
    {

        Node *node = root;
        for (int i = 0; i < s.size(); i++)
        {

            if (node->containsChar(s[i]))
            {
                node = node->getNode(s[i]);
            }
            else
            {
                node->put(s[i], new Node());
                node = node->getNode(s[i]);
            }
        }

        node->flag = true;
    }
    bool searchTrie(string s, Node *node)
    {
        if (s.size() == 0)
            return node->flag;
        int present = false;

        if (s[0] == '.')
        {
            for (int i = 0; i < 26; i++)
            {
                if (node->containsChar(i + 'a'))
                    present = present || searchTrie(s.substr(1, s.size() - 1), node->getNode(i + 'a'));
            }
        }
        else
        {
            if (node->containsChar(s[0]))
                present = present || searchTrie(s.substr(1, s.size() - 1), node->getNode(s[0]));
            else
                return false;
        }
        return present;
    }

    bool search(string word)
    {
        return searchTrie(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */