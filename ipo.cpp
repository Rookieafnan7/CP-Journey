// Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

// You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.

// Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

// Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.

// The answer is guaranteed to fit in a 32-bit signed integer.

// Example 1:

// Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
// Output: 4
// Explanation: Since your initial capital is 0, you can only start the project indexed 0.
// After finishing it you will obtain profit 1 and your capital becomes 1.
// With capital 1, you can either start the project indexed 1 or the project indexed 2.
// Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
// Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
// Example 2:

// Input: k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
// Output: 6

// Constraints:

// 1 <= k <= 105
// 0 <= w <= 109
// n == profits.length
// n == capital.length
// 1 <= n <= 105
// 0 <= profits[i] <= 104
// 0 <= capital[i] <= 109

// using two heaps one is maxheap of profits and the other is minheap of capital that is sequentially added in each iteration.
class BestSolution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &p, vector<int> &c)
    {
        priority_queue<pair<int, int>> pq1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
        for (int i = 0; i < p.size(); i++)
        {
            if (c[i] > w)
                pq2.push({c[i], p[i]});
            else
                pq1.push({p[i], c[i]});
        }

        while (k > 0 && (!pq1.empty() || !pq2.empty()))
        {
            while (!pq2.empty() && pq2.top().first <= w)
            {
                pq1.push({pq2.top().second, pq2.top().first});
                pq2.pop();
            }
            if (!pq1.empty())
            {
                w += pq1.top().first;
                pq1.pop();
                k--;
            }
            else
                return w;
        }
        return w;
    }
};

// Using DFS, it's a naive approach
class BadSolution
{
public:
    void dfs(vector<int> &profits, vector<int> &capital, vector<int> &pres, int i, int &k, int &w, int &maxS)
    {
        maxS = max(maxS, w);
        if (i == k || i >= capital.size())
        {
            // cout<<"w 2 "<<w<<endl;
            // cout<<"end"<<endl;
            return;
        }
        for (int j = 0; j < capital.size(); j++)
        {
            if (pres[j])
                continue;
            if (capital[j] <= w)
            {
                // cout<<"w 1 "<<w<<endl;
                // cout<<"cap "<<capital[j]<<endl;
                // cout<<"prof "<<profits[j]<<endl;
                pres[j] = 1;
                // w-=capital[i];
                w += profits[j];
                dfs(profits, capital, pres, i + 1, k, w, maxS);
                // w+=capital[i];
                // cout<<"reach"<<endl;
                w -= profits[j];
                pres[j] = 0;
                // cout<<"w at end "<<w<<endl;
            }
            else
                continue;
        }
    }
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        vector<int> pres(profits.size(), 0);
        int maxS = w;
        dfs(profits, capital, pres, 0, k, w, maxS);
        return maxS;
    }
};