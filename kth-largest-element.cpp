// // https://leetcode.com/problems/kth-largest-element-in-an-array/description/?envType=study-plan-v2&envId=top-interview-150

// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Can you solve it without sorting?

// Example 1:

// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5
// Example 2:

// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
// Output: 4

// Constraints:

// 1 <= k <= nums.length <= 105
// -104 <= nums[i] <= 104

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// Quick Select Algorithm O(N) average time, worst case O(N^2) time, O(1) space since swapping happens in original array
class BestSolution
{
public:
    int findKthLargest(std::vector<int> &nums, int k)
    {
        int left = 0, right = nums.size() - 1;
        while (true)
        {
            int pivot_index = rand() % (right - left + 1) + left;
            int new_pivot_index = partition(nums, left, right, pivot_index);
            if (new_pivot_index == nums.size() - k)
            {
                return nums[new_pivot_index];
            }
            else if (new_pivot_index > nums.size() - k)
            {
                right = new_pivot_index - 1;
            }
            else
            {
                left = new_pivot_index + 1;
            }
        }
    }

private:
    int partition(std::vector<int> &nums, int left, int right, int pivot_index)
    {
        int pivot = nums[pivot_index];
        std::swap(nums[pivot_index], nums[right]);
        int stored_index = left;
        for (int i = left; i < right; i++)
        {
            if (nums[i] < pivot)
            {
                std::swap(nums[i], nums[stored_index]);
                stored_index++;
            }
        }
        std::swap(nums[right], nums[stored_index]);
        return stored_index;
    }
};

// Counter approach O(max - min || N) time complexity O(max - min) space complexity
// Among the fastest
class CounterSolution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        if (nums.size() < k)
            return -1;
        int max = nums[0];
        int min = nums[0];
        for (const int val : nums)
        {
            max = std::max(max, val);
            min = std::min(min, val);
        }
        std::vector<int> counts(max - min + 1, 0);
        for (const int val : nums)
        {
            counts[val - min]++;
        }

        for (int i = counts.size() - 1; i >= 0; --i)
        {
            k -= counts[i];
            if (k <= 0)
                return min + i;
        }
        return -1;
    }
};

// In between solution, good space and time complexity O(nlogk) time and O(k) space
class HeapSolution
{
public:
    int findKthLargest(std::vector<int> &nums, int k)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap(nums.begin(), nums.begin() + k);

        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] > min_heap.top())
            {
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }

        return min_heap.top();
    }
};

// O(N^2) average not ideal
class MyBadSolution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int size = nums.size();
        // cout<<"size "<<size<<endl;
        if (k > (size / 2))
        {
            int itr = size - k + 1;
            // cout<<"itr is "<<itr<<endl;
            for (int i = 0; i < itr; i++)
            {
                // cout<<"i "<<i<<endl;
                for (int j = size - 1; j >= 1 + i; j--)
                {
                    // cout<<"j "<<j<<endl;
                    if (nums[j] < nums[j - 1])
                    {
                        // cout<<"swap "<<nums[j]<<" "<<nums[j-1]<<endl;
                        int temp = nums[j - 1];
                        nums[j - 1] = nums[j];
                        nums[j] = temp;
                        // cout<<"swapped "<<nums[j]<<" "<<nums[j-1]<<endl;
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < size - 1 - i; j++)
                {
                    // cout<< nums[i]<<" "<< nums[i+1]<<endl;
                    if (nums[j] > nums[j + 1])
                    {
                        int temp = nums[j + 1];
                        nums[j + 1] = nums[j];
                        nums[j] = temp;
                    }
                }
            }
        }

        return nums[size - 1 - (k - 1)];
        // return k>(nums.size()/2)? nums[nums.size()-k] :nums[nums.size()-1-(k-1)];
    }
};