//TC : O(n)
//SC : O(n)
class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0' || s.empty())return 0;

        vector<int>dp(s.size()+1,0);
        dp[0] = 1;
        for(int i = 1;i <= s.size();++i){
            if(s[i-1] != '0')dp[i] += dp[i-1];
            if(i >=2 && s.substr(i-2,2) >= "10" && s.substr(i-2,2) <= "26")dp[i] += dp[i-2];
        }
        return dp.back();
    }
};
//121
//1
//2 21
//1 

//12
//1