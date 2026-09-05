class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> maps;

        for( int num:nums)
        {
            maps[num]++;
        }

        vector<pair<int,int>> arr;
        for( const auto& a: maps)
        {
            arr.push_back({a.second,a.first});
        }

        sort(arr.rbegin(), arr.rend());

        vector<int> res;
        for(int i = 0; i<k;++i)
        {
            res.push_back(arr[i].second);
        }
        return res;
    }
};
