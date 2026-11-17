class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for (auto& pre : prerequisites) {
            indegree[pre[1]]++;
            adj[pre[0]].push_back(pre[1]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int finish = 0;
        vector<int> output(numCourses);
        while(!q.empty())
        {
            int c = q.front();
            q.pop();
            output[numCourses - finish - 1] = c;
            finish++;
            for(int nei : adj[c])
            {
                indegree[nei]--;
                if(indegree[nei] == 0)
                {
                    q.push(nei);
                }
            }
        }

        if(finish != numCourses) return {};
        return output;
    }
};
