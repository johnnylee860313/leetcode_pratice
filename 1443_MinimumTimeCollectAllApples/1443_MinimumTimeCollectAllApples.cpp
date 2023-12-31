//find parent
//DFS, O(n)
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);

        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return dfs(adj,hasApple,0,-1);
    }

    int dfs(vector<vector<int>>& adj, vector<bool>& hasApple,int start,int parent){
        int time = 0;

        for(auto edge:adj[start]){
            //go deep to the leaf
            if(edge != parent) time = time + dfs(adj,hasApple,edge,start);
        }

        if(start == 0)return time;
        //if it doesn't have an apple then its time should be zero in case the root has an apple
        if(time == 0 && hasApple[start] == false)return 0;
        else return time+2;//back and forth
    }
};