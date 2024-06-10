//O(n)
//O(n)
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n,0);
        int res = INT_MIN;

        for(int i = 0;i < n;++i){
            dp[i] = energy[i];
        }

        for(int i = n-1;i >= 0;--i){
            int boundCheck = i + k;

            if(boundCheck > n-1){//out of bound,then still the same
                dp[i] = dp[i];
            }else{
                dp[i] = dp[i]+dp[boundCheck];
            }
            res = (res>dp[i]?res:dp[i]);
        }
        return res;
    }
};
