class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(const auto& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;
       
        if(!dfs(0,-1, adj, visited)) return false;
        
        return visited.size() == n;
    }

    bool dfs(int node, int parent, vector<vector<int>>& adj,unordered_set<int>& visited )
    {
        if(visited.find(node)!= visited.end()) return false;
        visited.insert(node);
        for(int nei: adj[node])
        {
            if(nei==parent) continue;
            if(! dfs(nei, node, adj, visited)) return false;
        }
        return true;
    }
};
