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

        

        for(int j = i ; j< candi.size();j++)
        {
            if(j > i && candi[j] == candi[j - 1])
            {
                continue;
            }

            if(cur + candi[j] > target) break;

            path.push_back(candi[j]);
            dfs(candi, target, j + 1, path, cur + candi[j]);
            path.pop_back();
        }
        
    }
};
