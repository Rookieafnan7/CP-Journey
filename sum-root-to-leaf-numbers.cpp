// https://leetcode.com/problems/sum-root-to-leaf-numbers/?envType=study-plan-v2&envId=top-interview-150
//  You are given the root of a binary tree containing digits from 0 to 9 only.

//     Each root -
//     to - leaf path in the tree represents a number.

//          For example,
//     the root - to - leaf path 1->2->3 represents the number 123. Return the total sum of all root - to - leaf numbers.Test cases are generated so that the answer will fit in a 32 - bit integer.

//                                                                                                                                                                                      A leaf node is a node with no children.

//                                                                                                                                                                                      Example 1 :

//     Input : root = [ 1, 2, 3 ] Output : 25 Explanation : The root - to - leaf path 1->2 represents the number 12. The root - to - leaf path 1->3 represents the number 13. Therefore,
//             sum = 12 + 13 = 25. Example 2 :

//     Input : root = [ 4, 9, 0, 5, 1 ] Output : 1026 Explanation : The root - to - leaf path 4->9->5 represents the number 495. The root - to - leaf path 4->9->1 represents the number 491. The root - to - leaf path 4->0 represents the number 40. Therefore,
//             sum = 495 + 491 + 40 = 1026.

//                                    Constraints :

//     The number of nodes in the tree is in the range[1, 1000]
//         .0 <= Node.val <= 9 The depth of the tree will not exceed 10.

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
#include <queue>
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

class BetterSolution
{
private:
    int result = 0;

public:
    void sumNumbersHelper(TreeNode *root, int pathSum)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            result += ((pathSum * 10) + root->val);
            return;
        }
        sumNumbersHelper(root->left, (pathSum * 10) + root->val);
        sumNumbersHelper(root->right, (pathSum * 10) + root->val);
        root->left = NULL;
        root->right = NULL;
    }
    int sumNumbers(TreeNode *root)
    {
        sumNumbersHelper(root, 0);
        return result;
    }
};

class MYSolution
{
public:
    int sumNumbers(TreeNode *root)
    {
        int sum = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                TreeNode *temp = q.front();
                if (temp->left)
                {
                    temp->left->val += temp->val * 10;
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    temp->right->val += temp->val * 10;
                    q.push(temp->right);
                }
                if (temp->left == nullptr && temp->right == nullptr)
                {
                    // cout<<"adding "<<temp->val<<endl;
                    sum += temp->val;
                }
                temp->left = NULL;
                temp->right = NULL;
                q.pop();
            }
        }
        return sum;
    }
};