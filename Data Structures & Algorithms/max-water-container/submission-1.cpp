class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max = 0;
        int l =0;
        int r = heights.size()-1;

        while(l<r)
        {
            int area = (r-l) * min(heights[l], heights[r]);
            if(area > max)
            {
                max = area;

            }

            if (heights[l] <= heights[r]) {
                l++;
            } else {
                r--;
            }
            
        }
        return max;
    }
};
