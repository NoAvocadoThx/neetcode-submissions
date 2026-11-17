class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() > n- 1) return false;
        vector<vector<int>> adj(n);

        for(const auto& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> Visited;
        if(!dfs(0, -1, Visited, adj)) return false;
        return Visited.size() == n;
        
    }


    bool dfs(int n, int prev, unordered_set<int>& Visited, vector<vector<int>>& adj)
    {
        if(Visited.count(n)) return false;
        Visited.insert(n);
        for(int node : adj[n])
        {
            if(node == prev) continue;

            if(!dfs(node, n, Visited, adj)) return false;
        }
        return true;
    }
};
