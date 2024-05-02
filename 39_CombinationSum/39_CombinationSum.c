// class Solution {
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<int>> ans;
//         vector<int> cur;
//         dfs(candidates,target,0,ans,cur);
//         return ans;
//     }
//     void dfs(vector<int> candidates, int target,int start,vector<vector<int>>& ans,vector<int>& cur){
//         if(target == 0)return ans.push_back({cur});        
//         if(target < 0 || start >= candidates.size())return;
//         // for(int i = start;i < candidates.size();++i){ <- this will lead to [2,2,3][3,2,2][2,3,2]
//         cur.push_back(candidates[start]);
//         dfs(candidates,target - candidates[start],start,ans,cur);
//         cur.pop_back();
//         dfs(candidates,target ,start+1,ans,cur);

//         // }
//     }
// };
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        combinationSumDFS(candidates, target, 0, out, res);
        return res;
    }
    void combinationSumDFS(vector<int>& candidates, int target, int start, vector<int>& out, vector<vector<int>>& res) {
        if (target < 0) return;
        if (target == 0) {res.push_back(out); return;}
        for (int i = start; i < candidates.size(); ++i) {
            out.push_back(candidates[i]);
            combinationSumDFS(candidates, target - candidates[i], i, out, res);
            out.pop_back();
        }
    }
};