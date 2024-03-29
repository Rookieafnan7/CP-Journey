// You are given a 0-indexed integer array costs where costs[i] is the cost of hiring the ith worker.

// You are also given two integers k and candidates. We want to hire exactly k workers according to the following rules:

// You will run k sessions and hire exactly one worker in each session.
// In each hiring session, choose the worker with the lowest cost from either the first candidates workers or the last candidates workers. Break the tie by the smallest index.
// For example, if costs = [3,2,7,7,1,2] and candidates = 2, then in the first hiring session, we will choose the 4th worker because they have the lowest cost [3,2,7,7,1,2].
// In the second hiring session, we will choose 1st worker because they have the same lowest cost as 4th worker but they have the smallest index [3,2,7,7,2]. Please note that the indexing may be changed in the process.
// If there are fewer than candidates workers remaining, choose the worker with the lowest cost among them. Break the tie by the smallest index.
// A worker can only be chosen once.
// Return the total cost to hire exactly k workers.

class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        int size = costs.size();
        long long cost = 0;
        // priority_queue<int> pq(costs.begin(), costs.end());
        priority_queue<int, vector<int>, greater<int>> left;
        priority_queue<int, vector<int>, greater<int>> right;
        int start = 0, end = size - 1;
        for (; start < min(size, candidates); start++)
            left.push(costs[start]);
        for (; start <= end && size - end <= candidates; end--)
            right.push(costs[end]);
        while ((!left.empty() || !right.empty()) && k > 0)
        {
            if (!left.empty() && !right.empty())
            {
                if (left.top() > right.top())
                {
                    cost += right.top();
                    right.pop();
                    if (start <= end)
                        right.push(costs[end--]);
                }
                else
                {
                    cost += left.top();
                    left.pop();
                    if (start <= end)
                        left.push(costs[start++]);
                }
            }
            else if (!left.empty())
            {
                cost += left.top();
                left.pop();
            }
            else
            {
                cost += right.top();
                right.pop();
            }
            k--;
        }
        return cost;
    }
};