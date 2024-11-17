//O(MN)

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                if (grid[i][j] == '1'){
                    dfs_search(grid, i, j, m , n);
                    islands++;
                }
            }
        }
        
        return islands;
    }
    
    void dfs_search(vector<vector<char>>& grid, int row, int col, int m, int n){
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] != '1')return;
        
        grid[row][col] = '#';
        
        dfs_search(grid, row+1, col, m, n);
        dfs_search(grid, row-1, col, m, n);
        dfs_search(grid, row, col+1, m, n);
        dfs_search(grid, row, col-1, m, n);
        
        return;
    }
};