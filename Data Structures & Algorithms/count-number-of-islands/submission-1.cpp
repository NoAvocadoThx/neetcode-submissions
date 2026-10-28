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
                    bfs(grid, i, j);
                    island++;
                }
            }
        }
        return island;
    }

    void bfs(vector<vector<char>>& grid, int r, int c)
    {
        queue<pair<int, int>> q;

        q.push({r,c});
        while(!q.empty())
        {
            auto element = q.front();
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int nr = element.first + directions[i][0];
                int nc = element.second + directions[i][1];
                if(nr >=0 && nc >=0 && nr <grid.size() && nc < grid[0].size() && grid[nr][nc] =='1')
                {
                     q.push({nr,nc});
                     grid[nr][nc] ='0';
                }
            }
            
        }
    }
};
