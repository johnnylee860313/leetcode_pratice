//O(N)
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n,false);

        for(auto connect:connections){//ex 0->1 => graph[0]:1 ; graph[1]:-0
            graph[connect[0]].push_back(connect[1]);
            graph[connect[1]].push_back(-connect[0]);
        }

        return dfs(graph,visited,0);
    }

    int dfs(vector<vector<int>>& graph,vector<bool>& visited,int from){
        int change = 0;
        visited[from] = 1;
        
        for(auto to:graph[from]){
            if(!visited[abs(to)])change += dfs(graph,visited,abs(to)) + (to > 0);
        }
        return change;
    }
};