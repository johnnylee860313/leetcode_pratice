//TC : O(n*target)
//SC : O(n+target)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0,target = 0;
    
        for(int i = 0;i < nums.size();++i){
            sum += nums[i];
        }
        // if(sum%2 != 0)return false;
        if(sum & 1)return false;

        target = sum >> 1;
        vector<bool> dp(target+1,false);
        dp[0] = true;

        for(auto num:nums){
            for(int i = target;i >= num;--i){
                dp[i] = dp[i] || dp[i-num];
            }
        }

        // cout<<dp[target]<<endl;
        return dp[target];
    }
};