//O(n)
//O(1)
class Solution {
public:
    int tribonacci(int n) {
        vector<int>dp(3,1);
        dp[0] = 0;
        // int sum_last3 = 0;
        
        if(n == 0)return dp[0];
        if(n == 1)return dp[1];
        if(n == 2)return dp[2];

        for(int i = 3; i <= n;++i){
            int sum_last3 = dp[0] + dp[1] + dp[2];
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = sum_last3;
        }
        return dp[2];
    }
};