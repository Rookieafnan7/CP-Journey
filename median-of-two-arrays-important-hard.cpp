// https://leetcode.com/problems/median-of-two-sorted-arrays/description/?envType=study-plan-v2&envId=top-interview-150
// https://www.youtube.com/watch?v=F9c7LpRZWVQ
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

// Constraints:

// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -106 <= nums1[i], nums2[i] <= 106

#include <vector>
#include <climits>
using namespace std;

class BestSolution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        int left = (n1 + n2 + 1) / 2;
        int start = 0, end = n1;
        int fsize = n1 + n2;
        while (start <= end)
        {
            int mid1 = start + (end - start) / 2;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1)
                r1 = nums1[mid1];
            if (mid2 < n2)
                r2 = nums2[mid2];
            if (mid1 > 0)
                l1 = nums1[mid1 - 1];
            if (mid2 > 0)
                l2 = nums2[mid2 - 1];
            if (l1 <= r2 && l2 <= r1)
            {
                if (fsize % 2 == 0)
                {
                    return (double)(max(l1, l2) + min(r1, r2)) / 2;
                }
                else
                    return max(l1, l2);
            }
            else if (l1 > r2)
                end = mid1 - 1;
            else
                start = mid1 + 1;
        }
        return 0;
    }
};

// takes O(n logn ) complexity which is bad
class MyBadSolution
{
public:
    int findIndex(vector<int> &nums, int &num, int start, int end)
    {
        if (nums.size() == 0)
            return 0;
        if (nums[0] > num)
            return 0;
        if (nums[nums.size() - 1] < num)
            return nums.size();
        int ref = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == num)
            {
                ref = mid;
                start = mid + 1;
            }
            else if (nums[mid] < num)
            {
                ref = mid;
                start = mid + 1;
            }
            else if (nums[mid] > num)
            {
                end = mid - 1;
            }
        }
        return ref + 1;
    }
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int start = 0;
        for (auto &num : nums2)
        {
            int i = findIndex(nums1, num, start, nums1.size() - 1);
            nums1.insert(nums1.begin() + i, num);
            start = i;
        }
        double result;
        if (nums1.size() % 2 == 0)
            result = (double)(nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) / 2;
        else
            result = nums1[nums1.size() / 2];
        return result;
    }
};