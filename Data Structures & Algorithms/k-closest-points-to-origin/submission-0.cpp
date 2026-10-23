class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> q;

        for(auto& p:points)
        {
            int d = p[0] * p[0] + p[1] * p[1];
            q.push({d,{p[0], p[1]}});

            if(q.size() > k)
            {
                q.pop();
            }
        }

        vector<vector<int>> res;
        while (!q.empty()) {
            res.push_back({q.top().second.first,
                           q.top().second.second});
            q.pop();
        }
        return res;

    }
};
