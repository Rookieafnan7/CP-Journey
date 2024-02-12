// There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

// When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

// Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.

// Example 1:

// Input: rooms = [[1],[2],[3],[]]
// Output: true
// Explanation:
// We visit room 0 and pick up key 1.
// We then visit room 1 and pick up key 2.
// We then visit room 2 and pick up key 3.
// We then visit room 3.
// Since we were able to visit every room, we return true.
// Example 2:

// Input: rooms = [[1,3],[3,0,1],[2],[0]]
// Output: false
// Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.

// Constraints:

// n == rooms.length
// 2 <= n <= 1000
// 0 <= rooms[i].length <= 1000
// 1 <= sum(rooms[i].length) <= 3000
// 0 <= rooms[i][j] < n
// All the values of rooms[i] are unique.

class BestSolution
{
public:
    vector<bool> isVisted;
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        isVisted.resize(rooms.size(), false);
        dfs(0, rooms);

        for (int i = 0; i < rooms.size(); i++)
        {
            if (isVisted[i] == false)
            {
                return false;
            }
        }

        return true;
    }

    void dfs(int index, vector<vector<int>> &rooms)
    {
        if (isVisted[index] == true)
        {
            return;
        }

        isVisted[index] = true;
        for (int i = 0; i < rooms[index].size(); i++)
        {
            dfs(rooms[index][i], rooms);
        }
    }
};

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        if (rooms[0].size() == 0)
            return false;
        int size = rooms.size();
        unordered_set<int> check;
        check.insert(0);
        queue<int> q;
        for (auto &i : rooms[0])
        {
            if (check.count(i) == 0)
            {
                q.push(i);
                check.insert(i);
            }
        }
        while (check.size() < size && !q.empty())
        {
            int top = q.front();
            q.pop();
            for (auto &i : rooms[top])
                if (check.count(i) == 0)
                {
                    check.insert(i);
                    q.push(i);
                }
        }
        if (check.size() == size)
            return true;
        return false;
    }
};