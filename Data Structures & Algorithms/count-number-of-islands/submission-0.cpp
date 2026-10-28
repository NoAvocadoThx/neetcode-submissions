class Solution {
public:
  int directions[4][2] = {{1, 0}, {-1, 0},
                            {0, 1}, {0, -1}};
    int numIslands(vector<vector<char>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();
        int island = 0;
        for(int i =0; i< ROW;i++)
        {
            for(int j = 0;j<COL;j++)
            {
                if(grid[i][j]=='1')
                {
                dfs(grid, i, j);
                island++;
                }
            }
        }
        return island;
    }

    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        if(r < 0 || c< 0 || r>= grid.size() || c>= grid[0].size()  || grid[r][c] == '0') return;

        grid[r][c] = '0';

        for(int i = 0;i< 4;i++)
        {
            dfs(grid, r + directions[i][0], c+ directions[i][1]);
        }
    }
};
