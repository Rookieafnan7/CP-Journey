//https://leetcode.com/problems/average-of-levels-in-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150

// Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.
 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: [3.00000,14.50000,11.00000]
// Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
// Hence return [3, 14.5, 11].
// Example 2:


// Input: root = [3,9,20,15,7]
// Output: [3.00000,14.50000,11.00000]
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -231 <= Node.val <= 231 - 1




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */



#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        val = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
    TreeNode(int x)
    {
        val = x;
        this->left = nullptr;
        this->right = nullptr;
    }
    TreeNode(int x, TreeNode *left, TreeNode *right)
    {
        val = x;
        this->left = left;
        this->right = right;
    }
};


class BestSolution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector <double> answer;
        if(root == nullptr){
            return answer;
        }
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            double sum = 0;
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto node = q.front();
                q.pop();
                sum += node -> val;
                if(node -> left != nullptr) {
                    q.push(node -> left);
                }
                if(node -> right != nullptr) {
                    q.push(node -> right);
                }
            }
            double average = sum / size;
            answer.push_back(average);
        }
        root -> left = nullptr;
        root -> right = nullptr; 
        return answer;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class MySolution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> tempArray;
        if(root == nullptr) return vector<double>(1,0);

        // int num = 1;
        queue<pair<TreeNode*,int>> nodeQ;
        map<int,pair<double,int>> levelStore;
        nodeQ.push(make_pair(root,0));
        while(!nodeQ.empty()){
            if(levelStore.count(nodeQ.front().second)==0){
                levelStore[nodeQ.front().second] = make_pair(nodeQ.front().first->val,1);
            }else{
                levelStore[nodeQ.front().second] = make_pair(levelStore[nodeQ.front().second].first+nodeQ.front().first->val,levelStore[nodeQ.front().second].second+1);
            }
            if(nodeQ.front().first->left!=nullptr){
                nodeQ.push(make_pair(nodeQ.front().first->left,nodeQ.front().second+1));
            }
            if(nodeQ.front().first->right!=nullptr){
                nodeQ.push(make_pair(nodeQ.front().first->right,nodeQ.front().second+1));
            }
            nodeQ.pop();
        }
        for (auto itr: levelStore){
            itr.second.first = itr.second.first/itr.second.second;
            tempArray.push_back(itr.second.first);
        }
        return tempArray;
    }
};