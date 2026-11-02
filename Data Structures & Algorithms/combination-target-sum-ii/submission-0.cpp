class Solution {
public:
vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, cur, 0, 0);
        return res;
    }

    void dfs(vector<int>& candidates, int target, vector<int> & path, int i, int cur)
    {
        if(target == cur)
        {
            res.push_back(path);
            return;
        }
        for(int idx = i; idx< candidates.size() ;idx++)
        {
            if(idx > i && candidates[idx] == candidates[idx - 1])
            {
                continue;
            }
        
            if( cur + candidates[idx] > target) break;

            path.push_back(candidates[idx]);
            dfs(candidates, target, path, idx + 1, cur + candidates[idx]);
            path.pop_back();

        }
    }
};
