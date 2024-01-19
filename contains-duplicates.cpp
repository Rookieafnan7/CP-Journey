// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

// Example 1:

// Input: nums = [1,2,3,1], k = 3
// Output: true
// Example 2:

// Input: nums = [1,0,1,1], k = 1
// Output: true
// Example 3:

// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false

// Constraints:

// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109
// 0 <= k <= 105
// Store Previous Index of a value
class BestSolution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            // mp.count() will tell whatever ith index that I want, have I seen it before?
            if (mp.count(nums[i]))
            {
                // if I have already seen this number, then check for condition abs(i - j) <= k
                if (abs(i - mp[nums[i]]) <= k)
                    return true;
            }
            // if I have not seen this number before, insert the number with its position in the map
            // and if the number is already present in the map, then update the position of that number
            mp[nums[i]] = i;
        }
        // after the complete traversal, if we don't find a pair to satisfy the condition, return false
        return false;
    }
};

class MyVeryBadSolution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        if (k == 0)
            return false;

        // if(k == 1) return true;
        // sort(nums.begin(), nums.end());
        // for(int i = 0; i < nums.size(); i++)
        unordered_set<int> present;
        int start = 0, end = min(start + k, (int)(nums.size()) - 1);
        for (int i = start; i <= end; i++)
            if (present.count(nums[i]))
                return true;
            else
                present.insert(nums[i]);

        present.erase(nums[start++]);
        end = start + k;
        while (end < nums.size())
            if (present.count(nums[end]))
                return true;
            else
            {
                present.erase(nums[start++]);
                present.insert(nums[end]);
                end = start + k;
            }

        return false;
    }
};