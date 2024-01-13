// 106. Construct Binary Tree from Inorder and Postorder Traversal
// Solved
// Medium
// Topics
// Companies
// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

// Example 1:

// Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: inorder = [-1], postorder = [-1]
// Output: [-1]
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

// COULD HAVE USED MAPS TO STORE INDEX OF INORDER ELEMENTS
class GoodSolution
{
public:
    TreeNode *helper(vector<int> &in, vector<int> &post, int start, int end)
    {
        if (start > end)
            return NULL;
        int center = post.back();
        post.pop_back();
        TreeNode *root = new TreeNode(center);
        auto it = std::find(in.begin() + start, in.begin() + end + 1, center);
        int index;
        if (it != in.end())
            index = std::distance(in.begin(), it);
        else
            return NULL;
        root->right = helper(in, post, index + 1, end);
        root->left = helper(in, post, start, index - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return helper(inorder, postorder, 0, inorder.size() - 1);
    }
};