class Solution {
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> Visiting;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0;i< numCourses;i++)
        {
            preMap[i] = {};
        }

        for(const auto& pre: prerequisites)
        {
            preMap[pre[0]].push_back(pre[1]);
        }

        for(int i=0;i< numCourses;i++)
        {
            if(!dfs(i)) return false;
        }
        return true;
    }

    bool dfs(int n)
    {
        if(preMap[n].empty()) return true;
        if(Visiting.find(n) != Visiting.end()) return false;

        Visiting.insert(n);
        for(int pre: preMap[n])
        {
            if(!dfs(pre)) return false;
        }
        Visiting.erase(n);
        preMap[n].clear();
        return true;

    }
};
