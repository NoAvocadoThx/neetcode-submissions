class Solution {
    int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                if (dfs(board, word, 0, r, c))
                {
 return true;
                }
                   
        return false;
    }

private:
    // 当前在 (r, c)，要匹配 word[idx]
    bool dfs(vector<vector<char>>& board, string word, int i, int r, int c) 
    {
        if(r < 0 || c < 0 || r >=board.size() || c >= board[0].size()) return false;
        if(word[i] != board[r][c]) return false;
        if(i == word.size() - 1) return true;

        char tmp = board[r][c];
        board[r][c] = ',';
        for(int d = 0; d<4;d++)
        {
           if( dfs(board, word, i + 1, r + directions[d][0], c + directions[d][1]))
           {
                board[r][c] = tmp;
                return true;
           }
        }
          board[r][c] = tmp;
          return false;
    }
};