class Solution {
public:
    int directions[4][2] = {{1,0},{-1,0}, {0,1}, {0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int mins = 0;
        int fresh = 0;
        queue<pair<int, int>> q;

        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0 ; c< COLS ; c++)
            {
                if(grid[r][c] == 2)
                {
                    q.push({r,c});

                }
                if(grid[r][c] == 1)
                {
                    fresh++;
                }
            }
        }

        while(fresh > 0 && !q.empty())
        {
        
            int length  = q.size();
            for(int i = 0 ; i<length; i++)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int d = 0 ;d < 4;d++)
                {
                    int r = row + directions[d][0];
                    int c = col + directions[d][1];

                    if(r < 0 || c < 0 || r >= ROWS || c >= COLS || grid[r][c] !=1 ) continue;
                    if(grid[r][c] == 1)
                    {
                        fresh--;
                    }
                    grid[r][c] = 2;
                   
                    q.push({r,c});
                }
            }
             mins++;
        }


        return fresh >0? -1 : mins;
    }
};
