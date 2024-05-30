//O(n)
//O(n)
// class Solution {
// public:
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         vector<int> dp(days.size()+1,INT_MAX);
//         dp[days.size()] = 0;

//         for(int i = days.size()-1;i >= 0;--i){
//             for(int j = 0;j < costs.size();++j){
//                 if(j == 0){
//                     auto it = lower_bound(days.begin()+i,days.end(),days[i]+1);
//                     dp[i] = min(dp[i],dp[it-days.begin()] + costs[j]);
//                     // cout<<"i = "<<i<<" "<<days[i]<<", dp[i] = "<<dp[i]<<" "<<it-days.begin()<<endl;
//                 }else if(j == 1){
//                     auto it = lower_bound(days.begin()+i,days.end(),days[i]+7);
//                     dp[i] = min(dp[i],dp[it-days.begin()] + costs[j]);
//                     // cout<<"i = "<<i<<" "<<days[i]<<", dp[i] = "<<dp[i]<<endl;
//                 }else if(j == 2){
//                     auto it = lower_bound(days.begin()+i,days.end(),days[i]+30);
//                     dp[i] = min(dp[i],dp[it-days.begin()] + costs[j]);
//                     // cout<<"i = "<<i<<" "<<days[i]<<", dp[i] = "<<dp[i]<<endl;
//                 }
//             }
//         }
//         return dp[0];
//     }
// };

// O(n^2)
//O(n)
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1,INT_MAX);
        dp[0] = 0;

        for(int i = 1;i <= days.size();++i){
            dp[i] = min(dp[i],dp[i-1]+costs[0]);
            for(int j = 1; j <=i ;++j){
                // if(days[j-1]+1 > days[i-1]){
                //     dp[i] = min(dp[i],dp[j-1]+costs[0]);
                // }
                if(days[j-1]+7 > days[i-1]){
                    dp[i] = min(dp[i],dp[j-1]+costs[1]);
                }
                if(days[j-1]+30 > days[i-1]){
                    dp[i] = min(dp[i],dp[j-1]+costs[2]);
                }
            }
        }
        return dp.back();
    }
};

