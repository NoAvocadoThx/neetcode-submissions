class Solution {
public:
   
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> visit(n, false);
        for(const auto& edge:edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        for(int i = 0; i < n;i++)
        {
            if(!visit[i])
            {
                dfs(graph, i, visit);
                res++;
            }
        }
      
        return res;
    }

    void dfs(const vector<vector<int>>& adj, int node,  vector<bool>& visit)
    {
        visit[node] =true;
        for(int nei : adj[node])
        {
            if(!visit[nei])
            {
                dfs(adj, nei, visit);
            }
        }
    }
};
