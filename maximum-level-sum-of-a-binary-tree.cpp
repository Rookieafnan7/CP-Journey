// Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

// Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        queue<TreeNode *> q;
        int minLevel = 1;
        int level = 0;
        int sum = INT_MIN;
        q.push(root);
        while (!q.empty())
        {
            level++;
            int lsum = 0;
            int n = q.size();
            while (n--)
            {
                TreeNode *top = q.front();
                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
                q.pop();
                lsum += top->val;
            }
            if (sum < lsum)
            {
                sum = lsum;
                minLevel = level;
            }
        }
        return minLevel;
    }
};