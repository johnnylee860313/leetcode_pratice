//DFS or DP

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        //DP
        sort(nums.begin(),nums.end());
        vector<int> dp(target+1,0);
        dp[0] = 1; // initialization

        for(int i = 1; i <= target;i++){
            for(int j = 0; j < nums.size(); j++){
                if(nums[j] <= target) dp[i] += dp[i - nums[j]];
                else break;
            }
        }
        return dp[target];
    }
};
// [1,2,3]
// 0 1 2 3 4 5
// 1 1 2 4 7 13
// [1,2,3,4]
// 0 1 2 3 4 5
// 1 1 2 4 7 15

//DP
vector<int>vector<> res;
    int combinationSum4ByDFS(vector<int>& nums, int target) 
    {
        dfs(nums, target,0,vector<int>());
        return res.size();
    }

    void dfs(vector<int>& a, int target, int sum,vector<int> one)
    {
        if (sum > target)
            return;
        else if (sum == target)
            res.push_back(one);
        else
        {
            for (int i = 0; i < a.size(); i++)
            {
                one.push_back(a[i]);
                dfs(a, target, sum + a[i], one);
                one.pop_back();
            }
        }
    }



