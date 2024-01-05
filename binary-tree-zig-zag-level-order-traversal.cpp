// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/?envType=study-plan-v2&envId=top-interview-150
// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]
// Example 2:

// Input: root = [1]
// Output: [[1]]
// Example 3:

// Input: root = []
// Output: []

// Constraints:

// The number of nodes in the tree is in the range [0, 2000].
// -100 <= Node.val <= 100

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
class BestSolution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        deque<TreeNode *> s;
        s.push_back(root);
        bool flag = true;
        while (!s.empty())
        {
            int n = s.size();
            vector<int> v;
            while (n--)
            {
                TreeNode *temp;
                if (flag)
                {
                    temp = s.front();
                    s.pop_front();
                    if (temp->left)
                        s.push_back(temp->left);
                    if (temp->right)
                        s.push_back(temp->right);
                }
                else
                {
                    temp = s.back();
                    s.pop_back();
                    if (temp->right)
                        s.push_front(temp->right);
                    if (temp->left)
                        s.push_front(temp->left);
                }
                v.push_back(temp->val);
            }
            flag = !flag;
            res.push_back(v);
        }
        return res;
    }
};