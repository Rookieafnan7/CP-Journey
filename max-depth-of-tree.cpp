// https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/1119309103/?envType=study-plan-v2&envId=top-interview-150

// Given the root of a binary tree, return its maximum depth.

//                                         A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

//                                         Example 1 :

//     Input : root = [ 3, 9, 20, null, null, 15, 7 ] Output : 3 Example 2 :

//     Input : root = [ 1, null, 2 ] Output : 2

//                        Constraints :

//     The number of nodes in the tree is in the range[0, 104]
//         .- 100 <= Node.val <= 100

// COULD HAVE JUST USED SIMPLE RECURSION
#include <iostream>
#include <vector>
#include <queue>
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

// That was dumb

class BestSolution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return max(maxLeft, maxRight) + 1;
    }
};

class MySolution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<TreeNode *> q;
        int level = 0, size;
        q.push(root);
        while (!q.empty())
        {
            size = q.size();
            while (size--)
            {
                if (q.front()->left)
                {
                    q.push(q.front()->left);
                }
                if (q.front()->right)
                {
                    q.push(q.front()->right);
                }
                q.pop();
            }
            level++;
        }
        return level;
    }
};