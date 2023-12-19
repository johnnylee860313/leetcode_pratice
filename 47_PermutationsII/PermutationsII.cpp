class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        vector<bool> visited(nums.size(),0);
        sort(nums.begin(),nums.end());
        dfs(nums,ans,cur,visited);
        return ans;
    }
    void dfs(vector<int>& nums,vector<vector<int>>& ans,vector<int>& cur,vector<bool>& visited){
        if(cur.size() == nums.size()){
            ans.push_back(cur);
            return;    
        }

        for(int i = 0;i < nums.size();++i){
            if(visited[i])continue;
            if(i > 0 && nums[i]==nums[i-1]&& !visited[i - 1] )continue;//same number and never visited 

            visited[i] = true;
            cur.push_back(nums[i]);
            // cout<<cur.back()<<endl;
            dfs(nums,ans,cur,visited);
            cur.pop_back();
            visited[i] = false;
        }
    }
};