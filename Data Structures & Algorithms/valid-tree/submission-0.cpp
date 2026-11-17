class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() > n - 1) return false;
         vector<vector<int>> adj(n);

         for(const auto& edge: edges)
         {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
         }
        unordered_set<int> Visiting;
        
        if(!dfs(0, -1, Visiting, adj)) return false;
        
        return Visiting.size() == n;
    }


    bool dfs(int n, int parent, unordered_set<int>& Visiting,  vector<vector<int>>& adj)
    {
        if(Visiting.find(n) != Visiting.end()) return false;
        

        Visiting.insert(n);
        for(int nei : adj[n])
        {
            if(nei == parent) continue;
            if(!dfs(nei, n, Visiting, adj)) return false;
        }
        return true;
    }
};
