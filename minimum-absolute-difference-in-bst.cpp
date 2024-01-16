// Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

// Example 1:

// Input: root = [4,2,6,1,3]
// Output: 1
// Example 2:

// Input: root = [1,0,48,null,null,12,49]
// Output: 1

// Constraints:

// The number of nodes in the tree is in the range [2, 104].
// 0 <= Node.val <= 105

// Note: This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
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
class Solution
{
public:
    int mindiff = INT_MAX;

    int getMinimumDifference(TreeNode *root)
    {
        if (root->left)
        {
            int tdiff = root->val - root->left->val;
            mindiff = min(mindiff, tdiff);
            TreeNode *temp = root->left->right;
            while (temp)
            {
                tdiff = root->val - temp->val;
                mindiff = min(mindiff, tdiff);
                temp = temp->right;
            }
            getMinimumDifference(root->left);
        }
        if (root->right)
        {
            int tdiff = root->right->val - root->val;
            mindiff = min(mindiff, tdiff);
            TreeNode *temp = root->right->left;
            while (temp)
            {
                tdiff = temp->val - root->val;
                mindiff = min(mindiff, tdiff);
                temp = temp->left;
            }
            getMinimumDifference(root->right);
        }
        return mindiff;
    }
};