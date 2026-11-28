class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegree(n);
        vector<vector<int>> adj(n);

        for(auto& pre : prerequisites)
        {
            adj[pre[0]].push_back(pre[1]);
            indegree[pre[1]]++;
        }

        queue<int> q;
        int finish = 0;

        for(int i=0;i<n;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> res(n);

        while(!q.empty())
        {
            int c = q.front();
            q.pop();
            res[n-finish - 1] = c;
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

        if(finish == n) return res;
        return {};
    }
};
