class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> preMap(n);
        vector<int> inDegree(n, 0);

        for(const auto& pre: prerequisites)
        {
            preMap[pre[0]].push_back(pre[1]);
            inDegree[pre[1]]++;
        }


        queue<int> q;
        int finish = 0;

        for(int i=0;i<n;i++)
        {
            if(inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int c = q.front();

            q.pop();
            finish++;

            for(int nei: preMap[c])
            {
                inDegree[nei]--;
                if(inDegree[nei] == 0)
                {
                    q.push(nei);
                }
            }
        }
        return finish == n;
    }
};
