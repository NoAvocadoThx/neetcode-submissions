class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> preProd(nums.size(), 1);
        vector<int> sufProd(nums.size(), 1);
        vector<int> res(nums.size());
      
        for(int i = 1; i < nums.size();i++)
        {
            preProd[i] = nums[i - 1] * preProd[i-1]; 
        }

        for(int i = nums.size()-2; i>=0;i--)
        {
            sufProd[i] = nums[i+1] * sufProd[i+1];
        }

        for(int i = 0 ; i < nums.size();i++)
        {
            res[i] = preProd[i] * sufProd[i];
        }
        return res;
    }
};


//[1,2,4,6]

//1 2 ,8, 1

