class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        // nums[i], freq
        vector<vector<int>> freq(nums.size() + 1);

        for(int i: nums)
        {
            count[i]++;
        }

        for(auto& c: count)
        {
            freq[c.second].push_back(c.first);
        }
        vector<int> res;
        for(int i = freq.size() - 1;i>=0;i-- )
        {
            for(int j = 0 ; j< freq[i].size();j++)
            {
                res.push_back(freq[i][j]);
                if(res.size() == k)
                {
                    return res;
                }
            }
        }
        return res;
    }
};
