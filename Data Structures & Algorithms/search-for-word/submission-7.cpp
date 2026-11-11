class Solution {
public:
int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    bool exist(vector<vector<char>>& board, string word) 
    {
        for(int r = 0; r< board.size();r++)
        {
            for(int c = 0; c< board[0].size();c++)
            {
                if(dfs(board, word, r, c, 0))
                {
                    return true;
                }
            }
        }    
        return false;
    }



    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i)
    {
        if(r >= board.size() || c >= board[0].size() || r < 0 || c < 0 ) return false;

        if(board[r][c] != word[i]) return false;

        if(word.size() == i + 1) return true;
        char tmp = board[r][c];
        board[r][c] = '#';
        for(int d = 0;d< 4; d++)
        {
           if( dfs(board, word, r + directions[d][0], c+ directions[d][1], i + 1))
           {
            board[r][c] = tmp;
            return true;
           }
        }
        board[r][c] = tmp;
        return false;

    }
};
