class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int largest = 0;
        while( l < r )
        {
            int area = 0;
            if(heights[l] < heights[r])
            {
                area = (r-l) * heights[l];      
                l++;        
            }
            else
            {
                area = (r-l) * heights[r];  
                r--;          
            }
            largest = max(area, largest);

        }
        return largest;
    }
};
