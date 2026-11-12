class Solution {
public:
 vector<vector<int>>  res;
    vector<vector<int>> combinationSum2(vector<int>& candi, int target) {
        sort(candi.begin(), candi.end());
        vector<int> comb;
        dfs(candi, target, 0, 0, comb);
        return res;
    }


    void dfs(vector<int>& candi, int target, int i, int curSum, vector<int>& comb)
    {
        if(curSum == target)
        {
            res.push_back(comb);
            return;
        }

        if(i >= candi.size() || curSum > target) return;

        comb.push_back(candi[i]);
        dfs(candi, target, i + 1, curSum+ candi[i], comb);
        comb.pop_back();
        while( i+1 < candi.size() && candi[i] == candi[i + 1])
        {
            i++;
        }
        dfs(candi, target, i + 1, curSum, comb);
    }
};
