//O(m*n*dfs) -> O(4^len(word)) 
// 4 is because 4 dir
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(),vector<bool>( board[0].size()));
        for(int i = 0;i < board.size();++i){
            for(int j = 0; j < board[0].size(); ++j){
                if (DFS_wordSearch(board, visited, word, 0, i, j))return true;
            }
        }
        return false;
    }
    bool DFS_wordSearch(vector<vector<char>>& board, vector<vector<bool>>& visited, 
                        string word, int index, int row, int col)
    {
        if (index == word.size())return true;
        
        if (row >= board.size() || 
            row < 0 || 
            col >= board[0].size()|| 
            col < 0 ||
            board[row][col] != word[index] || 
            visited[row][col]) return false;
         
        visited[row][col] = true;
        
        bool exist = DFS_wordSearch(board, visited, word, index+1, row+1, col) ||
                        DFS_wordSearch(board, visited, word, index+1, row-1, col) ||
                        DFS_wordSearch(board, visited, word, index+1, row, col+1) ||
                        DFS_wordSearch(board, visited, word, index+1, row, col-1);
        
        visited[row][col] = false;
        return exist;
    }
};