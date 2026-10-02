class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROW = matrix.size();
        int COL =matrix[0].size();
        int l=0;
        int r = ROW*COL - 1;
        // m = row *n + col
        while(l <= r)
        {
            int m = l+ (r - l)/2;
            int val = matrix[m/COL][m%COL];
            if(val < target)
            {
                l = m +1;
            }
            else if (val > target)
            {
                r = m -1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
