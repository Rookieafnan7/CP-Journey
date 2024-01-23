// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

// Example 1:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
// Example 2:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
// Output: 0
// Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

// Constraints:

// 1 <= beginWord.length <= 10
// endWord.length == beginWord.length
// 1 <= wordList.length <= 5000
// wordList[i].length == beginWord.length
// beginWord, endWord, and wordList[i] consist of lowercase English letters.
// beginWord != endWord
// All the words in wordList are unique.
class BestSolution
{
public:
    int ladderLength(string bW, string eW, vector<string> &wList)
    {
        unordered_set<string> s(wList.begin(), wList.end());
        queue<pair<string, int>> q;
        q.push({bW, 1});
        while (!q.empty())
        {
            auto w = q.front().first;
            auto steps = q.front().second;
            q.pop();
            if (w == eW)
            {
                return steps;
            }
            for (int i = 0; i < w.size(); i++)
            {
                char x = w[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    w[i] = c;
                    if (s.find(w) != s.end())
                    {
                        s.erase(w);
                        q.push({w, steps + 1});
                    }
                }
                w[i] = x;
            }
        }
        return 0;
    }
};
class BetterSolution
{
public:
    class Trie
    {
    public:
        Trie *node[26];
        bool flag;
        Trie()
        {
            for (int i = 0; i < 26; i++)
            {
                node[i] = NULL;
            }
            flag = false;
        }
        bool hasChar(char c)
        {
            if (node[c - 'a'])
                return true;
            return false;
        }
        Trie *returnNode(char c)
        {
            return node[c - 'a'];
        }
        Trie *createAndMove(char c)
        {
            node[c - 'a'] = new Trie();
            return node[c - 'a'];
        }
    };
    void insertWord(Trie *root, string &word)
    {
        Trie *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (temp->hasChar(word[i]))
            {
                temp = temp->returnNode(word[i]);
            }
            else
            {
                temp = temp->createAndMove(word[i]);
            }
        }
        temp->flag = true;
    }
    bool containsWord(Trie *root, string &word)
    {
        Trie *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (temp->hasChar(word[i]))
            {
                temp = temp->returnNode(word[i]);
            }
            else
                return false;
        }
        return temp->flag;
    }
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        Trie *root = new Trie();
        unordered_set<string> s;
        insertWord(root, beginWord);
        s.insert(beginWord);
        for (auto &s : wordList)
            insertWord(root, s);
        if (!containsWord(root, endWord))
            return 0;
        queue<string> q;
        q.push(beginWord);
        int len = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                string top = q.front();
                q.pop();
                if (top == endWord)
                    return len + 1;
                Trie *temp = root;
                for (int i = 0; i < top.size(); i++)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        if (temp->hasChar('a' + j))
                        {
                            string t = top;
                            t[i] = j + 'a';
                            if (containsWord(root, t) && !s.count(t))
                            {
                                q.push(t);
                                s.insert(t);
                            }
                        }
                    }
                    temp = temp->returnNode(top[i]);
                }
            }
            len++;
        }
        return 0;
    }
};

class BadSolution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_map<int, unordered_set<char>> ref;
        for (int i = 0; i < beginWord.size(); i++)
            for (int j = 0; j < wordList.size(); j++)
                ref[i].insert(wordList[j][i]);
        unordered_set<string> pres;
        pres.insert(beginWord);
        queue<string> q;
        q.push(beginWord);
        int len = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                string top = q.front();
                q.pop();
                if (top == endWord)
                    return len + 1;
                for (int i = 0; i < top.size(); i++)
                {
                    for (auto &c : ref[i])
                    {
                        string temp = top;
                        temp[i] = c;
                        if (pres.count(temp) == 0 && find(wordList.begin(), wordList.end(), temp) != wordList.end())
                        {
                            q.push(temp);
                            pres.insert(temp);
                        }
                        else
                            continue;
                    }
                }
            }
            len++;
        }
        return 0;
    }
};