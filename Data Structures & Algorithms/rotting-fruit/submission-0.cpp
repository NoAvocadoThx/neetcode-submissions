class Solution {
public:
    int directions[4][2] = {{1,0}, {-1, 0}, {0,1}, {0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int fresh = 0;
        int time = 0;
        for(int i = 0 ; i< grid.size();i++)
        {
            for(int j = 0 ;j< grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    fresh++;
                }

                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
            }
        }

        while(fresh > 0 && !q.empty())
        {
            int length = q.size();
            for(int i =0;i<length;i++)
            {
                 int row = q.front().first;
                 int col = q.front().second;
                 q.pop();
                 for(int d =0;d <4;d++)
                 {
                    int r = row + directions[d][0];
                    int c = col + directions[d][1];

                    if(r >=0 && c>=0 && r< grid.size() && c< grid[0].size() && grid[r][c] == 1)
                    {
                        fresh--;
                        q.push({r,c});
                        grid[r][c] = 2;
                    }
                 }
            }
            time++;
           
        }
        return fresh == 0 ? time : -1;
        
    }
};
