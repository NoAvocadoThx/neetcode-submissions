class Solution {
public:
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0 ;i < numCourses; i++)
        {
            preMap[i] = {};
        }

        for(const auto& p: prerequisites)
        {
            preMap[p[0]].push_back(p[1]);
        }

        for(int i = 0 ; i< numCourses; i++)
        {
            if(!dfs(i)) return false;
        }

        return true;
    }


    bool dfs(int course)
    {
        if(visited.count(course)) return false;
        if(preMap[course].empty()) return true;

        visited.insert(course);
        for(int pre: preMap[course])
        {
            if(!dfs(pre)) return false;
        }
        visited.erase(course);
        preMap[course].clear();
        return true;
    }
};
