// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left
// subtree
//  of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

// Example 1:

// Input: root = [2,1,3]
// Output: true
// Example 2:

// Input: root = [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -231 <= Node.val <= 231 - 1

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <cfloat>
#include <limits>
#include <cstddef>
using namespace std;

// using inorder traversal property
class MySolution
{
public:
    long long save = numeric_limits<long long>::min();
    bool isValidBST(TreeNode *root)
    {
        // cout<<INT_MIN;
        if (!root)
            return true;
        bool left = isValidBST(root->left);
        if (!left)
            return false;
        // bool lres;
        if (save >= root->val)
            return false;
        else
            save = root->val;
        return isValidBST(root->right);
    }
};

// using local maxima and minima
class AltSolution
{
    bool isPossible(TreeNode *root, long long int l, long long int r)
    {
        if (root == NULL)
            return true;
        if (root->val < r && root->val > l)
        {
            return isPossible(root->left, l, root->val) && isPossible(root->right, root->val, r);
        }
        else
            return false;
    }

public:
    bool isValidBST(TreeNode *root)
    {
        long long int min = -1000000000000, max = 1000000000000;
        return isPossible(root, min, max);
    }
};