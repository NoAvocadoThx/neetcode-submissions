class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int product = 1;
        int zeroCount = 0;
        for(int i = 0; i<(int)nums.size();++i)
        {
            if( nums[i]!=0)
            {
                product *= nums[i];
            }
            else
            {
                zeroCount++;
            }
        }
        if(zeroCount >1) 
        {
            return vector<int>(nums.size(),0);
        }
        for(int i=0;i<(int)nums.size();i++)
        {
            if(zeroCount > 0 )
            {
                if(nums[i] == 0)
                {
                    ans.push_back(product);
                }
                else
                {
                    ans.push_back(0);
                }
            }
            else
            {
                 ans.push_back(product/nums[i]);
            }
               
            
          
        }
        return ans;
    }
};
