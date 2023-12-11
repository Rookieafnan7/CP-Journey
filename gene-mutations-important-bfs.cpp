//YouTube Video : https://www.youtube.com/watch?v=H3kSFSv-t30
// https://leetcode.com/problems/minimum-genetic-mutation/?envType=study-plan-v2&envId=top-interview-150

// A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

// Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.

// For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
// There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

// Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

// Note that the starting point is assumed to be valid, so it might not be included in the bank.

 

// Example 1:

// Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
// Output: 1
// Example 2:

// Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
// Output: 2
 

// Constraints:

// 0 <= bank.length <= 10
// startGene.length == endGene.length == bank[i].length == 8
// startGene, endGene, and bank[i] consist of only the characters ['A', 'C', 'G', 'T'].

#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>
#include<queue>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bankset(bank.begin(), bank.end()); //quick access
        
        unordered_set<string> visited;
        
        queue<string> que;
        
        que.push(start);
        visited.insert(start);
        
        int level = 0;
        
        while(!que.empty()) {
            int n = que.size();
            
            while(n--) {
                string curr = que.front();
                que.pop();
                
                if(curr == end) //reached target
                    return level;
                
                for(char ch : "ACGT") {
                    
                    for(int i = 0; i<curr.length(); i++) {
                        string neighbour = curr;
                        neighbour[i] = ch; //first try with 'A', then 'C', then 'G', 'T'
                        
                        if(visited.find(neighbour) == visited.end() &&
                          bankset.find(neighbour) != bankset.end()) {
                            visited.insert(neighbour);
                            que.push(neighbour);
                        }
                        
                        
                    }
                }
            }
            level++;
        }
        
        return -1;
    }
};