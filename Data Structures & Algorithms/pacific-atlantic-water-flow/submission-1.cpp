class Solution {
public:
    int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();
        vector<vector<bool>> pac(ROWS,vector<bool> (COLS, false));
        vector<vector<bool>> atl(ROWS,vector<bool> (COLS, false));

        for(int c = 0; c< COLS;c++)
        {
            dfs(0, c, pac, heights);
            dfs(ROWS- 1, c, atl, heights);
        }

        for(int r = 0; r < ROWS;r++)
        {
            dfs(r, 0, pac,heights);
            dfs(r, COLS - 1, atl, heights);
        }

        vector<vector<int>> res;

        for(int r = 0 ;r <ROWS ;r++)
        {
            for(int c = 0; c < COLS ; c++)
            {
                if(pac[r][c] && atl[r][c])
                {
                    res.push_back({r,c});
                }
            }
        }
        return res;
    }


    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights)
    {
        ocean[r][c] = true;
        for(int i = 0;i<4;i++)
        {
            int row = r + directions[i][0];
            int col = c +directions[i][1];
            if(row>=0 && col>=0 && row < heights.size() && col < heights[0].size() && !ocean[row][col] && heights[row][col] >= heights[r][c])
            {
                dfs(row, col, ocean, heights);
            }
        }
    }
};
