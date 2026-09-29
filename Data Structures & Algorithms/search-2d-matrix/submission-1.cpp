class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix[0].size();
        int COLS = matrix.size();
        int left = 0;
        int right = ROWS * COLS - 1;
        while(left <= right)
        {
            int m  = left + (right - left)/2;
            // index = rows * n + col
            int val = matrix[m/ROWS][m%ROWS];
            if(target < val)
            {
               
                 right = m - 1;
            }
            else if(target > val)
            {
                left = m +1 ;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
