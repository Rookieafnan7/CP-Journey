//https://leetcode.com/problems/binary-tree-level-order-traversal/description/?envType=study-plan-v2&envId=top-interview-150

// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
// Example 2:

// Input: root = [1]
// Output: [[1]]
// Example 3:

// Input: root = []
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [0, 2000].
// -1000 <= Node.val <= 1000

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

class BestSolution 
{
    public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
    vector<vector<int>>ans;
    queue<TreeNode*>q;
    if(root==NULL){
        return ans;
    }
    q.push(root);
    while(!q.empty()){
        int size =q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            TreeNode*node=q.front();
            q.pop();
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
    }
};


class MySolution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> tempArr;
        queue<TreeNode*> nodeQ;
        if(root)
            nodeQ.push(root);
        else return tempArr;
        int index = 0;
        while(!nodeQ.empty()){
            int size = nodeQ.size();
            tempArr.push_back(vector<int>());
            for(int i = 0; i < size; i++){
                tempArr[index].push_back(nodeQ.front()->val);
                if(nodeQ.front()->left) nodeQ.push(nodeQ.front()->left);
                if(nodeQ.front()->right) nodeQ.push(nodeQ.front()->right);
                nodeQ.pop();
            }
            index++;
        }
        return tempArr;
    }
};

