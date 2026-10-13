class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] > 0) break;
            if(i>0 && nums[i] == nums[i-1]) continue;
            int l = i+1;
            int r = nums.size()- 1;
            
            while(l<r)
            {
                int sum = nums[l] + nums[i] + nums[r];
                if(sum > 0)
                {
                    r--;
                }
                else if(sum < 0)
                {
                    l++;
                }
                else
                {
                    res.push_back({nums[l],nums[i], nums[r] });
                    r--;
                    l++;
                    while(l<r && nums[l] == nums[l-1])
                    {
                        l++;
                    }
                }
            }
          
        }
        return res;
    }
};
