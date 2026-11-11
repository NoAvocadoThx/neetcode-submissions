class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candi, int target) {
        sort(candi.begin(), candi.end());
        vector<int> path;
        dfs(candi, target, 0, path, 0);
        return res;
    }

    void dfs(vector<int>& candi, int target, int i, vector<int>& path, int cur)
    {
        if(cur  == target)
        {
            res.push_back(path);
            return;
        }

        if(cur > target || i>= candi.size()) return;

        path.push_back(candi[i]);
        dfs(candi, target, i + 1, path, cur + candi[i]);
        path.pop_back();

        while(i+ 1 < candi.size() && candi[i] == candi[i + 1])
        {
            i++;
        }
        dfs(candi, target, i + 1, path, cur);
        
    }
};
