class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum2(vector<int>& candi, int target) {
        sort(candi.begin(), candi.end());
vector<int> cur;
        dfs(candi, target, 0,0, cur);

        return res;
    }


    void dfs(vector<int>& candi, int target, int i, int cur, vector<int>& path)
    {
        if(target == cur)
        {
            res.push_back(path);
            return;
        }

        for(int j = i; j< candi.size(); j++)
        {
            if(j >i && candi[j] == candi[j - 1])
            {
                continue;
            }

            if(cur + candi[j] > target) break;

            path.push_back(candi[j]);
            dfs(candi, target, j + 1, cur + candi[j], path);
            path.pop_back();
        }
    }
};
