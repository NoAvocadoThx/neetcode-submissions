class Solution {
public:
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> Visiting;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0 ; i< numCourses;i++)
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

    bool dfs(int course)
    {
        if(Visiting.count(course)) return false;
        if(preMap[course].empty()) return true;

        Visiting.insert(course);

        for(int c : preMap[course])
        {
            if(!dfs(c)) return false;
        }

        Visiting.erase(course);
        preMap[course].clear();
        return true;
    }
};
