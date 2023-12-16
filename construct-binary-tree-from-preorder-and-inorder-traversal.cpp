// // https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/?envType=study-plan-v2&envId=top-interview-150
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

// Example 1:

// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: preorder = [-1], inorder = [-1]
// Output: [-1]

// Constraints:

// 1 <= preorder.length <= 3000
// inorder.length == preorder.length
// -3000 <= preorder[i], inorder[i] <= 3000
// preorder and inorder consist of unique values.
// Each value of inorder also appears in preorder.
// preorder is guaranteed to be the preorder traversal of the tree.
// inorder is guaranteed to be the inorder traversal of the tree.

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

#include <vector>
#include <cstddef>
#include <bits/stdc++.h>
// #include <
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

// Hash map is used to retrieve inorder indexes instead of searching

class BestSolution
{
public:
    TreeNode *constructTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &mp)
    {
        if (preStart > preEnd || inStart > inEnd)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inRoot = mp[root->val];
        int elemLeft = inRoot - inStart;
        root->left = constructTree(preorder, preStart + 1, preStart + elemLeft, inorder, inStart, inRoot - 1, mp);
        root->right = constructTree(preorder, preStart + elemLeft + 1, preEnd, inorder, inRoot + 1, inEnd, mp);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() != inorder.size())
        {
            return NULL;
        }
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        return constructTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
    }
};

class MySolution
{
public:
    TreeNode *recur(vector<int> &pre, int &prei, vector<int> in)
    {
        if (in.size() == 0)
            return NULL;
        int temp = pre[prei++];
        TreeNode *node = new TreeNode(temp);
        // cout<<"temp "<<temp<<endl;
        auto div = find(in.begin(), in.end(), temp);
        if (div != in.begin())
        {
            node->left = recur(pre, prei, vector<int>(in.begin(), div));
        }
        else
            node->left = NULL;
        if (div != (in.end() - 1))
        {
            node->right = recur(pre, prei, vector<int>(div + 1, in.end()));
        }
        else
        {
            node->right = NULL;
        }

        return node;
    }
    // TreeNode* right(vector<int>&pre,int& prei,vector<int> in){
    //     if(in.size()==0) return NULL;
    // }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0)
            return NULL;
        TreeNode *root = new TreeNode(preorder[0]);
        auto div = find(inorder.begin(), inorder.end(), preorder[0]);
        int prei = 1;
        // cout<<"start "<<preorder[0]<<endl;
        if (div != inorder.begin())
        {
            root->left = recur(preorder, prei, vector<int>(inorder.begin(), div));
        }
        else
        {
            root->left = NULL;
        }
        if (div != (inorder.end() - 1))
        {
            root->right = recur(preorder, prei, vector<int>(div + 1, inorder.end()));
        }
        else
        {
            root->right = NULL;
        }
        return root;
    }
};