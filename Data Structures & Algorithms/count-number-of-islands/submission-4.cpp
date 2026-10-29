class Solution {
public:
 int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int numIslands(vector<vector<char>>& grid) {
       int ROW = grid.size();
       int COL = grid[0].size();
        int islands = 0;
       for(int r = 0;r<ROW;r++)
       {
        for(int c=0;c<COL;c++)
        {
            if(grid[r][c] == '1')
            {
                bfs(grid, r,c);
                islands++;     
            }
        }
       }
       return islands;
    }


    void bfs(vector<vector<char>>& grid, int r, int c)
    {
       queue<pair<int, int>> q;
       q.push({r,c});

       while(!q.empty())
       {
            auto pairs = q.front();
            q.pop();
           

            for(int i = 0; i< 4;i++)
            {
                 int rows = pairs.first+ directions[i][0];
                 int cols = pairs.second+ directions[i][1];
                if(rows >=0 && cols >= 0 && rows < grid.size() && cols< grid[0].size() && grid[rows][cols] == '1')
                {
                    q.push({rows, cols  });
                    grid[rows][cols] ='0';
                }
            }
       }
    }
};
