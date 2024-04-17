class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int res = 0;
        queue<int> q{{1}};//count from 1 in bottom left
        vector<bool> visited(n * n +1);

        while(!q.empty()){
            for(int k = q.size();k > 0;--k){
                int num = q.front();q.pop();

                if(num == n * n)return res;
                for(int i = 1;i <= 6 && num + i <= n * n;++i){
                    auto pos = getPosition(num+i,n);
                    int next = board[pos[0]][pos[1]] == -1 ? (num + i) : board[pos[0]][pos[1]];
                    if(visited[next])continue;
                    visited[next] = true;
                    q.push(next);
                }
            }
            ++res;  
        }
        return -1;
    }

//normal 2D array is counted from top left but the grid here is counted from bottom left
    vector<int> getPosition(int num,int n){
        int x = (num - 1) / n, y = (num - 1) % n;
        if (x % 2 == 1) y = n - 1 - y;
        x = n - 1 - x;
        return {x, y};
    }
};
