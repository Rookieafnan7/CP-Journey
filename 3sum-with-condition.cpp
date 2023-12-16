// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0 and i < j < k.

// Notice that the solution set must not contain duplicate triplets.

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation:
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
// Example 2:

// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.

// Constraints:

// 3 <= nums.length <= 3000
// -105 <= nums[i] <= 105

#include <vector>
// #include <vector>
#include <deque>
#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        unordered_map<int, deque<int>> m;
        // vector<int> sortedArr(nums);
        set<vector<int>> solSet;
        // sort(sortedArr.begin(),sortedArr.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(nums[i]) != m.end())
                m[nums[i]].push_back(i);
            else
                m[nums[i]] = deque<int>(1, i);
        }
        for (int it1 = 0; it1 < nums.size() - 2; it1++)
        {
            int val1 = nums[it1];
            cout << "it1 front " << m[val1].front() << endl;
            m[val1].pop_front();
            unordered_map<int, deque<int>> t(m);
            for (int it2 = it1 + 1; it2 < nums.size() - 1; it2++)
            {
                cout << "it2 front " << t[nums[it2]].front() << endl;
                t[nums[it2]].pop_front();
                int val2 = val1 + nums[it2];
                int val3 = -(val1 + nums[it2]);
                if (t.find(val3) != t.end())
                {
                    for (int i = 0; i < t[val3].size(); i++)
                    {
                        vector<int> temp;
                        temp.push_back(nums[it1]);
                        temp.push_back(nums[it2]);
                        temp.push_back(val3);
                        solSet.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> sol;
        for (auto &v : solSet)
            sol.push_back(v);
        return sol;
    }
};