class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> dups;
        for(int i=0;i<nums.size();++i)
        {
            if(dups.find(nums[i])== dups.end())
            {
                dups.insert(nums[i]);
            }
            else
            {
                return true;
            }
          
        }
        return false;
    }
};