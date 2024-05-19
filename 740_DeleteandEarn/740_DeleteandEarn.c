// class Solution {
// public:
//     int deleteAndEarn(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) return 0;
//         vector<int> cnt(10001, 0), dp(10001, 0);
//         for (int i = 0; i < n; i++) cnt[nums[i]]++;
//         dp[1] = cnt[1];
//         for (int i = 2; i <= 10000; i++)
//             dp[i] = max(dp[i-1], cnt[i] * i + dp[i-2]);
//         return dp[10000];
//     }
// };
//O(n),O(n)
//p.s simliar to House Robber question
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxnum=0;
        int trans[10001]={0};
        for(int i:nums){
            trans[i]+=i;
            maxnum=max(maxnum,i);
        }
        int dp[maxnum+1];
        dp[0]=trans[0];
        dp[1]=max(trans[1],trans[0]);
        for(int i=2;i<=maxnum;i++){
            dp[i] = max(dp[i - 1], dp[i - 2] +trans[i]);
        }
        return dp[maxnum];
    }
};