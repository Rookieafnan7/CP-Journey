// https : // leetcode.com/problems/minimum-size-subarray-sum/?envType=study-plan-v2&envId=top-interview-150
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

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
#include <bits/stdc++.h>
// #include <vector>
#include <deque>
#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

// Two Flag Approach after sorting
class BestSolution1
{
public:
    vector<vector<int>> threeSum(vector<int> &num)
    {
        vector<vector<int>> result;
        std::sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); i++)
        {
            int target = -num[i];
            int front = i + 1;
            int back = num.size() - 1;

            while (front < back)
            {
                int sum = num[front] + num[back];
                // Finding answer which start from number num[i]
                if (sum < target)
                    front++;
                else if (sum > target)
                    back--;
                else
                {
                    vector<int> triplet = {num[i], num[front], num[back]};
                    result.push_back(triplet);

                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while (front < back && num[front] == triplet[1])
                        front++;
                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (front < back && num[back] == triplet[2])
                        back--;
                }
            }
            // Processing duplicates of Number 1
            while (i + 1 < num.size() && num[i + 1] == num[i])
                i++;
        }
        return result;
    }
};

// Alternative Hashmap strategy

class AltSolution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end()); // Sorted Array
        if (nums.size() < 3)
        { // Base Case 1
            return {};
        }
        if (nums[0] > 0)
        { // Base Case 2
            return {};
        }
        unordered_map<int, int> hashMap;
        vector<vector<int>> answer;
        for (int i = 0; i < nums.size(); ++i)
        { // Hashing of Indices
            hashMap[nums[i]] = i;
        }

        for (int i = 0; i < nums.size() - 2; ++i)
        { // Traversing the array to fix the number.
            if (nums[i] > 0)
            { // If number fixed is +ve, stop there because we can't make it zero by searching after it.
                break;
            }
            for (int j = i + 1; j < nums.size() - 1; ++j)
            { // Fixing another number after first number
                int required = -1 * (nums[i] + nums[j]);
                // To make sum 0, we would require the -ve sum of both fixed numbers.
                if (hashMap.count(required) && hashMap.find(required)->second > j)
                {
                    answer.push_back({nums[i],
                                      nums[j],
                                      required});
                }
                j = hashMap.find(nums[j])->second; // Update j to last occurence of 2nd fixed number to avoid duplicate triplets.
            }
            i = hashMap.find(nums[i])->second; // Update i to last occurence of 1st fixed number to avoid duplicate triplets.
        }
        return answer; // Return answer vector.
    }
};

// IT WORKS BUT IS NOT EFFICIENT, COULD HAVE BEEN MORE SPACE EFFIECIENT, NO NEED FOR HAS

class MyBadSolution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        unordered_map<int, int> m;
        vector<int> sortedArr(nums);
        set<vector<int>> solSet;
        vector<vector<int>> sol;
        sort(sortedArr.begin(), sortedArr.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(nums[i]) != m.end())
                m[nums[i]]++;
            else
                m[nums[i]] = 1;
        }
        // cout<<"Sorted Array";
        // for (int i = 0; i < sortedArr.size(); i++)
        //     cout<<" "<<sortedArr[i];

        // cout<<endl;
        for (int it1 = 0; it1 < sortedArr.size(); it1++)
        {
            if (it1 > 0 && sortedArr[it1] == sortedArr[it1 - 1])
                continue;
            if (sortedArr[it1] > 0)
                break;

            int val1 = sortedArr[it1];
            if (val1 > 0)
                break;
            if (m[sortedArr[it1]] > 0)
                m[sortedArr[it1]]--;
            else
                continue;
            // else continue;
            // cout<<"it1 "<<sortedArr[it1]<<endl;
            unordered_map<int, int> t(m);
            for (int it2 = it1 + 1; it2 < sortedArr.size(); it2++)
            {

                // cout<<"it2 "<<sortedArr[it2]<<endl;
                t[sortedArr[it2]]--;
                int find = -(val1 + sortedArr[it2]);
                // cout<<"find "<<find<<endl;
                if (find < sortedArr[it2])
                    break;
                if (t.find(find) != t.end())
                {
                    if (t[find] > 0)
                    {

                        vector<int> temp;
                        temp.push_back(sortedArr[it1]);
                        temp.push_back(sortedArr[it2]);
                        temp.push_back(find);
                        solSet.insert(temp);
                    }
                }
            }
        }
        for (auto &v : solSet)
            sol.push_back(v);

        return sol;
    }
};
