class Solution {
public:
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visiting;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0;i< numCourses;i++)
        {
            preMap[i] = {};
        }

        for(const auto& p: prerequisites)
        {
            preMap[p[0]].push_back(p[1]);
        }

        for(int c = 0 ;c< numCourses;c++)
        {
            if(!dfs(c))
            {
                return false;
            }
        }
        return true;
    }


    bool dfs(int course)
    {
        if(visiting.count(course)) return false;
        if(preMap[course].empty()) return true;
        visiting.insert(course);
        for(int pre : preMap[course])
        {
            if(!dfs(pre))
            {
                return false;
            }
        }

        visiting.erase(course);
        preMap[course].clear();
        return true;
    }
};

// 2->1->0