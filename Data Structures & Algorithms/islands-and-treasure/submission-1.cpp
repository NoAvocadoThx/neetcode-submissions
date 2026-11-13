class Solution {
public:
    int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        queue<pair<int, int>> q;

        for(int r = 0;r < ROWS; r++)
        {
            for(int c = 0 ; c< COLS; c++)
            {
                if(grid[r][c] == 0)
                {
                    q.push({r,c});
                }
            }
        }

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int d = 0 ; d< 4; d++)
            {
                int r = row + directions[d][0];
                int c = col + directions[d][1];

                if(r < 0 || c < 0 || r >= ROWS || c >= COLS || grid[r][c] != INT_MAX) continue;
                
                
               
                grid[r][c] = grid[row][col] + 1;
                q.push({r,c});
                
            }
        }

    }
};
