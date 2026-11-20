class Solution {
public:
  int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;
        for(int r = 0;r < grid.size();r++)
        {
            for(int c = 0 ; c< grid[0].size() ;c++)
            {
                if(grid[r][c] == 1)
                {
                    fresh++;
                }
                if(grid[r][c] == 2)
                {
                    q.push({r,c});
                }
            }
        }


        int mins = 0;

        while(fresh > 0 && !q.empty())
        {
            
            int length = q.size();
            for(int i = 0 ; i< length;i++)
            {
                  int row = q.front().first;
                  int col = q.front().second;
                  q.pop();
                  for(int d  = 0; d< 4;d++)
                  {
                    int r = row + directions[d][0];
                    int c = col + directions[d][1];

                    if(r < 0 || c<0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != 1) continue;

                    fresh--;
                    q.push({r,c});
                    grid[r][c] = 2;

                  }
            }
          
            mins++;
            
        }
        return fresh != 0 ? -1: mins;
    }
};
