class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> maps;
        vector<vector<int>> freq(nums.size() + 1);
        for(int i=0;i<nums.size();i++)
        {
            maps[nums[i]]++;
        }

        for(const auto& entry: maps)
        {
            freq[entry.second].push_back(entry.first);
        }
        
        for(int i = freq.size() - 1; i>=0;i--)
        {
            for(int n :freq[i])
            {
                res.push_back(n);
                if(res.size() == k)
                {
                    return res;
                }
            }
        }
        return res;
    }
};
