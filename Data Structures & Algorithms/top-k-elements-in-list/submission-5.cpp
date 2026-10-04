class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> freq(nums.size() + 1);
        unordered_map<int, int> count;
        for(int i=0;i<nums.size();i++)
        {
            count[nums[i]] ++;
        }

        for(auto& c : count)
        {
            freq[c.second].push_back(c.first);
        }
        vector<int> res;
        for(int i = freq.size() - 1;i >=0;i--)
        {
            for(int j = 0;j< freq[i].size();j++)
            {
                if(res.size() == k)
                {
                    return res;
                }
                res.push_back(freq[i][j]);
            }
        }
        return res;
    }
};
