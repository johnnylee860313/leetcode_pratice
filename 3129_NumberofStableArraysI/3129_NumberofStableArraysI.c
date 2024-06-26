class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        /*dp[i][j][k]
        i for number of 0
        j for number of 1
        k for stable array end with 0 or 1*/
        vector<vector<vector<long>>> dp(zero+1,vector<vector<long>>(one+1,vector<long>(2)));
        constexpr int kMod = 1'000'000'007;

        //initialize when only 0
        for(int i = 0;i <= min(zero,limit);++i){
            dp[i][0][0] = 1;
        }
        //initialize when only 1
        for(int j = 0;j <= min(one,limit);++j){
            dp[0][j][1] = 1;
        }

        for(int i = 1;i <= zero;++i){
            for(int j = 1; j <= one;++j){
                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1] - (i - limit < 1? 0 : dp[i-limit-1][j][1])+ kMod) % kMod ;

                dp[i][j][1] = (dp[i][j-1][0] + dp[i][j-1][1] - (j - limit < 1? 0 : dp[i][j-limit-1][0])+ kMod) % kMod ;
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % kMod;
    
    }
};
