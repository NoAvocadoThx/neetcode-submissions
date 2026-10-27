class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prev(nums.size() , 1);
        vector<int> suf(nums.size() , 1);

        for(int i = 1; i< nums.size();i++)
        {   
            prev[i] = nums[i - 1] * prev[i-1];
        }

        for(int i = nums.size() - 2; i>=0;i--)
        {
            suf[i] = nums[i + 1] * suf[i+1];
        }

        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            res.push_back(prev[i]* suf[i]);
        }
        return res;
    }
};
