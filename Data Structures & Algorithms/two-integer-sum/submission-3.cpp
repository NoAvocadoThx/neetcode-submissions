class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> targets;
        for(int i = 0; i< nums.size();i++)
        {
         
            int rest = target - nums[i];
            if(targets.find(rest) != targets.end())
            {
                return {targets[rest], i};
            }
            targets[nums[i]] = i;
        }
        return {};
    }
};
