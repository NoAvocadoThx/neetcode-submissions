class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> freq(nums.size() + 1);
        vector<int> res;
        unordered_map<int, int> count;

        for(int i: nums)
        {
            count[i]++;
        }

        for(auto c: count)
        {
            freq[c.second].push_back(c.first);
        }

        for(int i = freq.size() - 1; i>=0;i--)
        {
            for(int j = 0 ; j< freq[i].size(); j++)
            {
                if(k> 0)
                {
                    k--;
                    res.push_back(freq[i][j]);
                }
            }
        }
        return res;

    }
};
