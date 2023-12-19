// https://leetcode.com/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-interview-150
// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

//                                                  You must write an algorithm that runs in
//                                                  O(n) time.

//                                                  Example 1 :

//     Input : nums = [ 100, 4, 200, 1, 3, 2 ] Output : 4 Explanation : The longest consecutive elements sequence is[1, 2, 3, 4].Therefore its length is 4. Example 2 :

//     Input : nums = [ 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 ] Output : 9

//                                                  Constraints :

//                                                  0 <= nums.length <= 105 - 109 <=
//                                                  nums[i] <= 109
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

// satisfies all the constrains although not the most efficient, i'm proud of it though
class MYSolution
{
public:
    class Node
    {
    public:
        int val;
        Node *next, *prev;
        Node(int x)
        {
            val = x;
            next = nullptr;
            prev = nullptr;
        }
        Node()
        {
            val = 0;
            next = nullptr;
            prev = nullptr;
        }
    };
    int longestConsecutive(vector<int> &nums)
    {

        unordered_map<int, Node *> m;
        // unordered_map<int,bool> m2;
        for (auto &num : nums)
        {
            // Node* temp;
            if (!m[num])
            {
                m[num] = new Node(num);
            }
            if (m[num + 1])
            {
                m[num]->next = m[num + 1];
                m[num + 1]->prev = m[num];
            }
            if (m[num - 1])
            {
                m[num - 1]->next = m[num];
                m[num]->prev = m[num - 1];
            }
        }
        int maxLen = 0;
        for (auto &n : nums)
        {
            if (m[n] == nullptr)
                continue;
            int store = 1;
            if (m[n]->next != nullptr || m[n]->prev != nullptr)
            {

                Node *temp = m[n]->prev;
                while (temp)
                {
                    store++;
                    m[temp->val] = nullptr;
                    Node *ptr = temp;
                    temp = temp->prev;
                    ptr->prev = nullptr;
                    ptr->next = nullptr;
                    // delete ptr;
                }
                temp = m[n]->next;
                while (temp)
                {
                    store++;
                    m[temp->val] = nullptr;
                    Node *ptr = temp;
                    temp = temp->next;
                    ptr->prev = nullptr;
                    ptr->next = nullptr;
                }
            }
            maxLen = max(store, maxLen);
        }
        return maxLen;
    }
};

// in terms of theoretical time complexity probably worse but okay, in practise better
class AltSolution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int longest = 1;
        unordered_set<int> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(nums[i]);
        }
        for (auto it : st)
        {
            if (st.find(it - 1) == st.end())
            {
                int cnt = 1;
                int x = it;
                while (st.find(x + 1) != st.end())
                {
                    x = x + 1;
                    cnt = cnt + 1;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};