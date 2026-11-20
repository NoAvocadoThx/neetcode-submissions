class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);

        for(const auto& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        for(int i=0;i< n;i++)
        {
            if(!visited[i])
            {
                dfs(adj, visited, i);
                res++;
            }
        }
        return res;

    }

    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int i)
    {
        visited[i] = true;

        for(int nei : adj[i])
        {
            if(!visited[nei])
            {
                dfs(adj, visited, nei);
            }
        }
    }
};
