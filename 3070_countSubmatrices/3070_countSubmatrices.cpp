//O(mn)
//O(mn)
//Prefix Sum & dp
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int countsum = 0;
        vector<vector<int>> accml(m+1,vector<int>(n+1,0));

        for(int i = 1;i <= m;++i){
            for(int j = 1;j <= n;++j){
                accml[i][j] = accml[i-1][j] + accml[i][j-1] - accml[i-1][j-1] + grid[i-1][j-1];
                if(accml[i][j] <= k)countsum++;
            }
        }
        return countsum;
    }
};