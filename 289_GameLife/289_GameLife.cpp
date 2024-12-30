/*
状态0： 死细胞转为死细胞
状态1： 活细胞转为活细胞
状态2： 活细胞转为死细胞
状态3： 死细胞转为活细胞
*/
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board[0].size();
        int m = board.size();
        vector<int> dx{-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> dy{-1, 0, 1, 1, 1, 0, -1, -1};
        
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                int cnt = 0;
                for(int k = 0;k < 8;++k){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n && 
                        (board[x][y] == 1 || board[x][y] == 2)) ++cnt;
                }
                if (board[i][j] && (cnt > 3 || cnt < 2))board[i][j] = 2;
                else if (!board[i][j] && cnt == 3)board[i][j] = 3;
            }
        }
        
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                board[i][j] %= 2;
            }
        }
        
    }
};