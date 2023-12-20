// https://leetcode.com/problems/container-with-most-water/description/?envType=study-plan-v2&envId=top-interview-150
// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

#include <vector>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxArea = 0;
        int left = 0, right = height.size() - 1;
        while (left < right)
        {
            // int currentArea = ;
            maxArea = max(maxArea, min(height[left], height[right]) * (right - left));
            if (height[left] <= height[right])
                left++;
            else
                right--;
        }

        // int maxArea = INT_MIN;
        // for(int i = 0; i < height.size(); i++){
        //     for(int j = height.size() - 1; j > i; j--){
        //         maxArea = max(maxArea, min(height[i], height[j]) * (j - i));
        //     }
        // }
        return maxArea;
    }
};