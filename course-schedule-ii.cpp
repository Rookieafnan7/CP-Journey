// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
// Example 2:

// Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
// So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
// Example 3:

// Input: numCourses = 1, prerequisites = []
// Output: [0]

// Constraints:

// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= numCourses * (numCourses - 1)
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// ai != bi
// All the pairs [ai, bi] are distinct.

// Best approach was to use indegrees and vector vector instead of map while focusing on the prerequisite course rather than the course to be taken

class BestSolution
{
public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);

        for (auto &it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        vector<int> ans;
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
            ans.push_back(node);
        }
        if (ans.size() == n)
            return ans;
        return {};
    }
};

class MySolution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> res;
        vector<int> check(numCourses, 1);
        unordered_map<int, set<int>> m;
        // unordered_set<int> s;
        for (int i = 0; i < prerequisites.size(); i++)
        {
            m[prerequisites[i][0]].insert(prerequisites[i][1]);
            check[prerequisites[i][0]] = 0;
        }
        for (int i = 0; i < numCourses; i++)
            if (check[i])
                res.push_back(i);
        // int count = prerequisites.size() - m.size();
        // cout<<"res"<<endl;
        // for(auto c : res){
        //     cout<<c << " ";
        // }
        // cout<<endl;
        if (res.size() == numCourses || res.size() == 0)
            return res;
        else
        {
            bool flag = true;
            while (flag)
            {
                flag = false;
                for (auto p : m)
                {
                    if (check[p.first])
                        continue;
                    // cout<<"p first "<< p.first<<endl;
                    bool temp = true;
                    for (auto num : p.second)
                        // cout<<"num "<< num<<endl;
                        if (check[num] == 0)
                        {
                            temp = false;
                            break;
                        }
                    if (temp)
                    {
                        res.push_back(p.first);
                        check[p.first] = 1;
                        flag = true;
                    }
                    else
                        continue;
                }
            }
        }
        if (res.size() == numCourses)
            return res;
        else
            return vector<int>();
        // if(count )
    }
};