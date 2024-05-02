//TC : N^2
//SC : N
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> adj[n];
        map<pair<int,int>,int> mp;
        for(int i = 0;i < roads.size();i++){
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
            mp[{roads[i][0],roads[i][1]}]++;
            mp[{roads[i][1],roads[i][0]}]++;
        }
        int maxi=0;
        for(int i = 0;i < n - 1;i++){
            for(int j = i + 1;j < n;j++){
                int size = adj[i].size() + adj[j].size();
                if(mp[{i,j}]){
                    size--;
                }
                maxi=max(maxi,size);
            }
        }
        return maxi;
    }
};