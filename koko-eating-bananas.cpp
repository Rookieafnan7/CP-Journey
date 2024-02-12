// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

// Example 1:

// Input: piles = [3,6,7,11], h = 8
// Output: 4
// Example 2:

// Input: piles = [30,11,23,4,20], h = 5
// Output: 30
// Example 3:

// Input: piles = [30,11,23,4,20], h = 6
// Output: 23

// Constraints:

// 1 <= piles.length <= 104
// piles.length <= h <= 109
// 1 <= piles[i] <= 109
class Solution
{
public:
    double hoursToEat(vector<int> &piles, int k)
    {
        // int i = 0;
        double total = 0;
        int size = piles.size();
        for (int i = 0; i < size; i++)
            if (piles[i] % k == 0)
                total += piles[i] / k;
            else
                total += piles[i] / k + 1;
        return total;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int max_el = *max_element(piles.begin(), piles.end());
        int minE = 0;
        int start = 1, end = max_el;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            double k = hoursToEat(piles, mid);
            if (k > h)
                start = mid + 1;
            else
            {
                minE = mid;
                end = mid - 1;
            }
        }
        return minE;
    }
};