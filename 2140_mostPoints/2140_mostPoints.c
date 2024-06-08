//O(n)
//O(n)
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        /* array to record the points, dp[i] menas the max points can possible get so far*/
        int n = questions.size();
        vector<long long>dp(n,0);
        dp[n-1] = questions[n-1][0];
        
        /* iterate backward from questions[n-2] */
        for(int i = n - 2;i >= 0; --i){
            int k = questions[i][1] + 1 + i;//after no.k form i
            /* if k > n , it means k is out of bound , there are no value to add on*/
            if(k >= n){
                dp[i] = questions[i][0] > dp[i+1]? questions[i][0]:dp[i+1];
            }else{
                dp[i] = (questions[i][0] + dp[k]) > dp[i+1]? (questions[i][0] + dp[k]):dp[i+1] ;
            }
        }
        return dp[0];
    }
};