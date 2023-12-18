// class Solution {
// public:
//     int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
//         int m = grid2.size();
//         int n = grid2[0].size();
//         int count = 0;

//         for(int i = 0;i < m;++i){
//             for(int j = 0;j < n;++j){
//                 if(grid2[i][j] == 1){
//                     if(dfs(grid1,grid2,i,j)){
//                         count++;
//                         cout<<i<<" "<<j<<endl;}
//                 }
//             }
//         }
//         return count;
//     }

//     bool dfs(vector<vector<int>>& grid1,vector<vector<int>>& grid2,int i,int j){
//         if(i < 0 || j < 0 || j >= grid2[0].size() || i >= grid2.size() || grid2[i][j]!= 1)return true;

//         if(grid1[i][j] != grid2[i][j])return false;

//         grid2[i][j] = -1;

//         return (dfs(grid1,grid2,i-1,j) & dfs(grid1,grid2,i+1,j) & dfs(grid1,grid2,i,j+1) & dfs(grid1,grid2,i,j-1));
//     }
    
// };
//O(mn)
class Solution {
 public:
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int ans = 0;

    for (int i = 0; i < grid2.size(); ++i)
      for (int j = 0; j < grid2[0].size(); ++j)
        if (grid2[i][j] == 1)
          ans += dfs(grid1, grid2, i, j);

    return ans;
  }

 private:
  int dfs(const vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i,
          int j) {
    if (i < 0 || i == grid1.size() || j < 0 || j == grid2[0].size() || grid2[i][j] != 1)
      return 1;

    grid2[i][j] = 2;  // Mark 2 as visited.

    return dfs(grid1, grid2, i + 1, j) & dfs(grid1, grid2, i - 1, j) &
           dfs(grid1, grid2, i, j + 1) & dfs(grid1, grid2, i, j - 1) &
           grid1[i][j];//check the 4 direction and grid1 is also island or not
  }
};