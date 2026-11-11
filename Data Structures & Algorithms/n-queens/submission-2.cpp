class Solution {
public:
vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        dfs(board, 0);
        return res;
    }

    void dfs(vector<string>& board, int r)
    {
        if(r == board.size())
        {
            res.push_back(board);
            return;
        }

        for(int i = 0;i< board.size();i++)
        {
            if(IsSafe(board, r, i))
            {
                board[r][i] = 'Q';
                dfs(board, r + 1);
                board[r][i] = '.';
            }
        }
    }




    bool IsSafe(vector<string>& board, int r, int c)
    {
        for(int i = r - 1; i>=0;i--)
        {
            if(board[i][c] == 'Q') return false;
        }

        for(int i = r- 1, j = c - 1; i>=0 && j>=0 ; i--,j--)
        {
            if(board[i][j] == 'Q') return false;
        }

        for(int i = r -1, j = c + 1; i>=0 && j< board.size(); i--,j++)
        {
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
};
