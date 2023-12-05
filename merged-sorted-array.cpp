// https://leetcode.com/problems/merge-sorted-array/?envType=study-plan-v2&envId=top-interview-150

// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

// Example 1:

// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
// Example 2:

// Input: nums1 = [1], m = 1, nums2 = [], n = 0
// Output: [1]
// Explanation: The arrays we are merging are [1] and [].
// The result of the merge is [1].
// Example 3:

// Input: nums1 = [0], m = 0, nums2 = [1], n = 1
// Output: [1]
// Explanation: The arrays we are merging are [] and [1].
// The result of the merge is [1].
// Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    // vector<int>& temp(nums2);
    // int max_end = m-1;
    // int mid;
    // while(temp.size()>0){
    //     int test;
    //     test = (temp.back());
    //     temp.pop_back();
    //     int ref = -1;
    //     int start = 0,end = max_end;
    //     while(start>=end){
    //         mid = start + (end - start)/2;
    //         if(nums1[mid]==test){
    //             ref = mid + 1;
    //             start = mid + 1;
    //         }else if(nums1[mid] > test){
    //             ref = mid;
    //             end = mid - 1;
    //         }else {
    //             start = mid+1;
    //         }
    //     }
    //     if(ref == -1){
    //         nums1.insert(nums1.begin()+max_end+1,test);
    //         max_end++;
    //     }else{
    //         nums1.insert(nums1.begin()+ref,test);
    //         max_end = ref;
    //     }
    // }
    if (nums2.size() == 0)
        return;
    if (m == 0)
    {
        for (int i = 0; i < nums2.size(); i++)
            nums1[i] = nums2[i];
        return;
    }
    // int start = 0, end = m - 1;
    int curr_index = m - 1;
    int ref_index = n - 1;

    while (ref_index >= 0)
    {
        if (curr_index == -1)
        {
            nums1.pop_back();
            nums1.insert(nums1.begin(), nums2[ref_index]);
            ref_index--;
        }
        else if (nums1[curr_index] <= nums2[ref_index])
        {
            // cout << nums1[curr_index] << " " << nums2[ref_index] << endl;
            // for (int i = 0; i < nums1.size(); i++)
            // {
            //     std::cout << nums1[i] << " ";
            // }
            // cout << endl;
            nums1.pop_back();
            nums1.insert(nums1.begin() + curr_index + 1, nums2[ref_index]);
            ref_index--;
            // curr_index++;
        }
        else
        {
            // if(curr_index)
            curr_index--;
        }
    }
    // for (int i = 0; i < nums1.size(); i++)
    // {
    //     std::cout << nums1[i] << " ";
    // }
    // cout << endl;
}
int main()
{
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};
    // std::cout << "Hello world";
    merge(nums1, nums1.size() - nums2.size(), nums2, nums2.size());

    for (int i = 0; i < nums1.size(); i++)
    {
        std::cout << nums1[i] << " ";
    }

    return 0;
}