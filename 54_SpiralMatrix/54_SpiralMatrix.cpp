//O(n),O(MN)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), dir = 0, now_i = 0, now_j = 0;
        vector<int> res;
        vector<vector<int>> visited(m, vector<int>(n));
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for(int k = 0;k < m * n;++k){
            res.push_back(matrix[now_i][now_j]);
            visited[now_i][now_j] = 1;
            
            int nxt_x = now_i + dirs[dir][0];
            int nxt_y = now_j + dirs[dir][1];
            
            //reach to the edge, turn direction
            if(nxt_x < 0 || nxt_x >= m || nxt_y < 0 || nxt_y >= n || visited[nxt_x][nxt_y] == 1){
                dir = (dir + 1) % 4;
                nxt_x = now_i + dirs[dir][0];
                nxt_y = now_j + dirs[dir][1];
            }

            now_i = nxt_x;
            now_j = nxt_y;
        }
        return res;
    }
};