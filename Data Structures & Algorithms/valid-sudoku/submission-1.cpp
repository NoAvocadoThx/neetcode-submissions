class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
       int n = board.size();
       int k = round(sqrt(n));
       vector<vector<bool>> row(n, vector<bool>(n)),
                         col(n, vector<bool>(n)),
                         box(n, vector<bool>(n));
        for(int r = 0 ; r< board.size();r++)
        {
            for(int c = 0 ; c< board[0].size();c++)
            {
                if (board[r][c] == '.') continue; 
                int digit = board[r][c]- '1';
                if (digit < 0 || digit >= n) return false;
                int boxIndex = (r/k) *k + (c/k);
                if(row[r][digit] || col[c][digit] || box[boxIndex][digit]) return false;
                row[r][digit] = col[c][digit] = box[boxIndex][digit] = true;
            }
        }
        return true;
    }
};
