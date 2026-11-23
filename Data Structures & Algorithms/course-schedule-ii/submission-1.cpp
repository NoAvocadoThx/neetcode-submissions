class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> preMap(n);
        vector<int> inDegree(n, 0);

        for(const auto& pre : prerequisites)
        {
            preMap[pre[0]].push_back(pre[1]);

            inDegree[pre[1]]++;
        }

        queue<int> q;

        for(int i=0;i< n;i++)
        {
            if(inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        int finish = 0;
        vector<int> res(n);
        while(!q.empty())
        {
            int course = q.front();
            q.pop();
            res[n-finish - 1] = course;
            finish++;
            for(int nei: preMap[course])
            {
                inDegree[nei]--;
                if(inDegree[nei] == 0)
                {
                    q.push(nei);
                }
            }
        }

        if(finish!= n) return {};
        return res;
    }
};
