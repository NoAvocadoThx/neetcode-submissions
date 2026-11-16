class Solution {
public:

    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visiting;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i< numCourses;i++)
        {
            preMap[i] = {};
        }

        for(const auto& c : prerequisites)
        {
            preMap[c[0]].push_back(c[1]);
        }

        for(int i = 0;i< numCourses;i++)
        {
            if(!dfs(i))return false;
        }
        return true;
    }

    bool dfs(int course)
    {
        if(visiting.count(course)) return false;
        if(preMap[course].empty()) return true;
        

        visiting.insert(course);

        for(int pre: preMap[course])
        {
            if(!dfs(pre)) return false;
        }
        visiting.erase(course);
        preMap[course].clear();
        return true;
    }
};
