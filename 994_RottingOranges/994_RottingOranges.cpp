//O(2n)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //bfs & queue
        int m = grid.size();
        int n = grid[0].size();
        // queue<pair<int,int>> q; -> this structure would be the same
        queue<vector<int>> q;
        vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};//4 direction
        int fresh = 0;
        int ans = 0;
        //put the initial rotting orange into queue;
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                if(grid[i][j] == 2) q.push({i,j});
                else if(grid[i][j] == 1)fresh++;
            }
        }
        // cout<<fresh<<" "<<q.front()[0]<<" "<<q.front()[1]<<endl;
        while(!q.empty() && fresh > 0){
            for (int k = q.size(); k > 0; --k) {
                auto curr = q.front();
                q.pop();
                for(int i = 0;i < dir.size();++i){
                    int x = curr[0]+dir[i][0];
                    int y = curr[1]+dir[i][1];
                    // int x = curr.first + dir[i][0]; -> if choose queue<pair<int,int>> as ds
                    // int y = curr.second + dir[i][1];

                    if(x >= m || x < 0 || y < 0 || y >= n || grid[x][y]!= 1)continue;

                    grid[x][y] = 2;
                    q.push({x,y});
                    fresh--;
                }
            }
            ans++;//count the step
        }
        return fresh > 0 ? -1 : ans;
    }
};
