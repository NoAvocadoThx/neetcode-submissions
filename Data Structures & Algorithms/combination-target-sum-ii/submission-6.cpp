class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candi, int target) {
        sort(candi.begin(), candi.end());
        vector<int> curSet;
        dfs(candi, target, 0, 0, curSet);
        return res;
    }

    void dfs(vector<int>& candi, int target, int i, int curSum, vector<int>& curSet)
    {
        if(curSum == target)
        {
            res.push_back(curSet);
            return;
        }
        if(curSum > target || i >= candi.size()) return;
        curSet.push_back(candi[i]);
        dfs(candi, target, i + 1, curSum+ candi[i],curSet);
        curSet.pop_back();
        while( i+1 < candi.size() && candi[i] == candi[i+1])
        {
            i++;
        }
        dfs(candi, target, i+1, curSum, curSet);
    }
};
