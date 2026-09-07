class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<(int)board.size();i++)
        {
            unordered_set<char> RowSeen;
            for(int j=0;j<(int)board[0].size();j++)
            {            
                if(board[i][j] == '.') continue;
                if(RowSeen.count(board[i][j])) return false;
                RowSeen.insert(board[i][j]);
            }
        }

        for(int i=0;i<(int)board[0].size();i++)
        {
            unordered_set<char> ColSeen;
            for(int j=0;j<(int)board.size();j++)
            {            
                if(board[j][i] == '.') continue;
                if(ColSeen.count(board[j][i])) return false;
                ColSeen.insert(board[j][i]);
            }
        }

        for(int square = 0; square < 9;square++)
        {
            unordered_set<char> Seen;
            for(int i = 0;i<3;i++)
            {
                for(int j = 0;j<3;j++)
                {
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    if(board[row][col] == '.') continue;
                    if(Seen.count(board[row][col])) return false;
                    Seen.insert(board[row][col]);
                }
            }
        }
        return true;
    }
};
