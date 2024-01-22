// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Example 1:

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9

// Constraints:

// n == height.length
// 1 <= n <= 2 * 104
// 0 <= height[i] <= 105

class BestSolution
{
public:
    int trap(vector<int> &h)
    {
        int l = 0, r = h.size() - 1, lmax = INT_MIN, rmax = INT_MIN, ans = 0;
        while (l < r)
        {
            lmax = max(lmax, h[l]);
            rmax = max(rmax, h[r]);
            ans += (lmax < rmax) ? lmax - h[l++] : rmax - h[r--];
        }
        return ans;
    }
};

class MySolution
{
public:
    int trap(vector<int> &height)
    {
        vector<int> rmax(height.size(), 0);
        // vector<int> lmax(rmax);
        // lmax[0] = 0;
        int size = height.size();
        rmax[size - 1] = 0;
        for (int i = size - 2; i >= 0; i--)
            rmax[i] = max(rmax[i + 1], height[i + 1]);
        int res = 0;
        int lmax = 0;
        for (int i = 1; i < size; i++)
        {
            lmax = max(lmax, height[i - 1]);
            if ((height[i] < lmax) && (height[i] < rmax[i]))
            {
                res += min(lmax, rmax[i]) - height[i];
            }
        }
        return res;
    }
};
{
    public :
        int trap(vector<int> & height){
            vector<int> rmax(height.size(), 0);
vector<int> lmax(rmax);
lmax[0] = 0;
int size = height.size();
rmax[size - 1] = 0;
for (int i = size - 2; i >= 0; i--)
    rmax[i] = max(rmax[i + 1], height[i + 1]);
for (int i = 1; i < size; i++)
    lmax[i] = max(lmax[i - 1], height[i - 1]);
int res = 0;
for (int i = 0; i < size; i++)
{
    if ((height[i] < lmax[i]) && (height[i] < rmax[i]))
    {
        res += min(lmax[i], rmax[i]) - height[i];
    }
}
return res;
}
}
;