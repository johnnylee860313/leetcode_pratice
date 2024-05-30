class Solution {
public:
    bool validPartition(vector<int>& nums) {
        vector<bool>dp(nums.size()+1,0);
        dp[0] = 1;
        //dp[i] means nums[0] to nums[i-1] are valid
        for(int i = 0;i <= nums.size();++i){
            if(dp[i] == 0)continue;
            if(i+1<nums.size() && nums[i]==nums[i+1])dp[i+2] = true;
            if(i+2<nums.size() && ((nums[i]+1==nums[i+1] && nums[i+1]+1==nums[i+2])
                        ||(nums[i]==nums[i+1]) && nums[i+1]==nums[i+2]))dp[i+3] = true;         
        }
        return dp.back();
    }
};