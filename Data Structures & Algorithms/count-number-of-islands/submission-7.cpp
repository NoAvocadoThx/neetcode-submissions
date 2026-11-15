class Solution {
public:
int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int ROWS = grid.size();
        int COLS = grid[0].size();
        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0 ; c< COLS; c++)
            {
                if(grid[r][c] == '1')
                {
                    dfs(grid, r, c);
                    islands++;
                }
            }
        }
        return islands;
    }

    void dfs(vector<vector<char>>& grid , int r, int c)
    {
        if(r <0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0') return;

        grid[r][c] = '0';

        for(int d = 0 ; d< 4; d++)
        {
            dfs(grid, r + directions[d][0], c + directions[d][1]);
        }
    }
};
