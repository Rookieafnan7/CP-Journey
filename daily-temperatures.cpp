// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
// Example 2:

// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]
// Example 3:

// Input: temperatures = [30,60,90]
// Output: [1,1,0]

// Constraints:

// 1 <= temperatures.length <= 105
// 30 <= temperatures[i] <= 100

class BestSolution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0);
        std::cout.tie(0);
    }

    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> ans(temperatures.size(), 0);

        for (int i = temperatures.size() - 2; i >= 0; --i)
        {
            const int temp = temperatures[i];

            if (temp < temperatures[i + 1])
            {
                ans[i] = 1;
            }
            else
            {
                int days = 1;

                while (temperatures[i + days] <= temp)
                {
                    if (ans[i + days] == 0)
                    {
                        days = 0;
                        break;
                    }

                    days += ans[i + days];
                }

                ans[i] = days;
            }
        }

        return ans;
    }
};

class MyBadSolution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        unordered_map<int, int> track;
        vector<int> res(temperatures.size(), 0);
        while (temperatures.size() > 0)
        {
            int save = temperatures.back();
            temperatures.pop_back();
            int index = temperatures.size();
            int early = INT_MAX;
            for (int i = save + 1; i <= 100; i++)
            {
                if (track.count(i))
                {
                    early = min(early, track[i]);
                }
                else
                    continue;
            }
            // cout<< save<<" "<< early << endl;
            track[save] = index;
            if (early == INT_MAX)
                res[index] = 0;
            else
                res[index] = early - index;
        }
        return res;
    }
};