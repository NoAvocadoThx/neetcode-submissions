class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        vector<int> preProd(nums.size());
        vector<int> sufProd(nums.size());
        preProd[0] = 1;
        sufProd[(int)nums.size() - 1] = 1;
        for(int i=1;i<(int) nums.size();++i)
        {
            preProd[i] = nums[i-1] * preProd[i-1];
        }
        for(int i = (int)nums.size() - 2 ; i>=0;i--)
        {
            sufProd[i] = nums[i + 1] * sufProd[i + 1];
        }

        for(int i = 0; i< (int) nums.size();i++)
        {
            ans[i] =  preProd[i]  * sufProd[i];
        }
        return ans;
    }
};
