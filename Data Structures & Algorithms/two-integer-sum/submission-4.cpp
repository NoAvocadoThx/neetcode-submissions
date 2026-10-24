class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
      
        for(int i=0;i<nums.size();i++)
        {
            int temp = target - nums[i];
            if(hash.find(temp) != hash.end())
            {
                return {hash[temp], i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};
