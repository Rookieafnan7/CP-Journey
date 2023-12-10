// https://leetcode.com/problems/gas-station/description/?envType=study-plan-v2&envId=top-interview-150

// There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

// Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique

// Example 1:

// Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
// Output: 3
// Explanation:
// Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
// Travel to station 4. Your tank = 4 - 1 + 5 = 8
// Travel to station 0. Your tank = 8 - 2 + 1 = 7
// Travel to station 1. Your tank = 7 - 3 + 2 = 6
// Travel to station 2. Your tank = 6 - 4 + 3 = 5
// Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
// Therefore, return 3 as the starting index.
// Example 2:

// Input: gas = [2,3,4], cost = [3,4,3]
// Output: -1
// Explanation:
// You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
// Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
// Travel to station 0. Your tank = 4 - 3 + 2 = 3
// Travel to station 1. Your tank = 3 - 3 + 3 = 3
// You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
// Therefore, you can't travel around the circuit once no matter where you start.

// Constraints:

// n == gas.length == cost.length
// 1 <= n <= 105
// 0 <= gas[i], cost[i] <= 104



//note: If the car starts from a gas station and cannot go further than a particular gas station, then no gas station within this range
// can be the start point

#include <iostream>
#include <vector>

using namespace std;

class BestSolution
{
private:
    constexpr static auto optimize = []()
    {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); };

public:
    int canCompleteCircuit(const std::vector<int> &gas, const std::vector<int> &cost) const
    {
        optimize();
        int currentGas = 0;
        int fullTripGasCost = 0;
        size_t potentialStart = 0;

        for (size_t i = 0; i < cost.size(); ++i)
        {
            auto currentRatio = gas[i] - cost[i];
            currentGas += currentRatio;
            fullTripGasCost += currentRatio;
            if (currentGas < 0)
            {
                potentialStart = i + 1;
                currentGas = 0;
            }
        }

        return fullTripGasCost >= 0 ? potentialStart : -1;
    }
};

class MySolution
{
public:
    int findStart(vector<int> &gas, vector<int> &cost, int start)
    {
        if (start > gas.size())
            return -1;
        int temp = -1;
        for (int i = start; i < gas.size(); i++)
        {
            if (gas[i] == cost[i] && gas[i] == 0)
            {
                temp = i;
                continue;
            }
            if (gas[i] >= cost[i])
            {
                temp = i;
                break;
            }
        }
        return temp;
    }
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int startIndex = -1, temp = 0;
        while (true)
        {
            if ((temp = findStart(gas, cost, temp)) == -1)
                return -1;
            // cout<< "temp " << temp << endl;
            int balance = gas[temp] - cost[temp], i;
            bool pass = true;
            // cout<< "init balance " << balance <<endl;
            for (i = 1; i < gas.size(); i++)
            {
                balance += gas[(temp + i) % gas.size()];
                // cout<<"btw bal "<< balance<<endl;
                if (cost[(temp + i) % gas.size()] == 0)
                    continue;
                if (balance < cost[(temp + i) % gas.size()])
                {
                    pass = false;
                    break;
                }
                else
                    balance -= cost[(temp + i) % cost.size()];
                // cout << "loop bal " << balance<< endl;
            }
            // cout<<"i end"<<i<<endl;
            // if((temp+i)%gas.size() == (temp+gas.size()-1)%gas.size()) return temp;
            if (pass)
                return temp;
            else
            {
                temp = temp + i + 1;
                continue;
            }
        }
        return -1;
    }
};