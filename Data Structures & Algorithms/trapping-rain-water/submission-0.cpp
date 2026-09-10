class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int leftMost = height[l];
        int rightMost = height[r];
        int ans = 0;
        while(l<r)
        {
            
            rightMost = max(height[r], rightMost);
            if(leftMost <rightMost)
            {

                l++;
                leftMost = max(height[l], leftMost);
                ans += leftMost - height[l];
            }
            else
            {
                r--;
                rightMost = max(height[r],rightMost);
                ans+=rightMost - height[r];
            }
        }
        return ans;
    }
};
