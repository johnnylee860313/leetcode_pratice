//O(n*n^1/2)
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 10000);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j * j <= i; ++j){
                dp[i] = min(dp[i], dp[i - j * j] + 1);
                // cout<<i<<" "<<j<<" "<< dp[i]<<endl;
            }
        }
        return dp[n];
    }
};
