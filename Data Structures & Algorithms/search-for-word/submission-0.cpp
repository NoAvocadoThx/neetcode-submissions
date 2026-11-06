class Solution {
    int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                if (dfs(board, word, r, c, 0))
                    return true;
        return false;
    }

private:
    // 当前在 (r, c)，要匹配 word[idx]
    bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int idx) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return false;
        if (board[r][c] != word[idx]) return false;      // 剪枝：字符不匹配立刻返回
        if (idx == word.size() - 1) return true;         // 最后一个字符也匹配上了

        char tmp = board[r][c];
        board[r][c] = '#';                               // 标记 visited（原地修改）
        for (auto& d : directions) {
            if (dfs(board, word, r + d[0], c + d[1], idx + 1)) {
                board[r][c] = tmp;
                return true;
            }
        }
        board[r][c] = tmp;                               // backtrack：恢复现场
        return false;
    }
};