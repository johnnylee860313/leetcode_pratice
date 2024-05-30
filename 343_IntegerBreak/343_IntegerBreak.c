//O(n^2)
class Solution {
public:
    int integerBreak(int n) {
        if(n==2)return 1;
        if(n==3)return 2;
        
        vector<int> dp(n+1, INT_MIN);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        
        for(int ind=4; ind<=n; ind++) {
            for(int i=ind-1; i>=1; i--) {
                dp[ind] = max(dp[ind], i * dp[ind - i]);
            }
        }
        
        return dp[n];
    }
};
