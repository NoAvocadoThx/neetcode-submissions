class Solution {
public:
int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    bool exist(vector<vector<char>>& board, string word) {
        for(int r = 0; r< board.size() ; r++)
        {
            for(int c = 0 ; c< board[0].size();c++)
            {
                if(dfs(board, word, 0, r, c))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int i, int r, int c)
    {
         if(word.size() == i ) return true;
        if(r < 0 || c < 0 || r >= board.size() || c>= board[0].size() ||word[i] != board[r][c] ||board[r][c] == '#') return false;
   
       
        
        char tmp = board[r][c];
        board[r][c] = '#';
        for(int d = 0 ; d < 4; d++)
        {
            if(dfs(board, word, i + 1, r + directions[d][0], c+ directions[d][1]))
            {
                board[r][c] = tmp; 
                return true;
            }
        }
        board[r][c] = tmp; 
        return false;
    }
};
