// class Solution {
// public:
//     int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
//         map<int,int> nums2_mp;
//         int wallCheck = 0;
//         int count = 0;

//         for(int i = 0;i < nums2.size();++i){
//             nums2_mp[i] = nums2[i];
//         }

//         for(int i = 0;i < nums1.size();++i){
//             auto lower = nums2_mp.lower_bound(wallCheck);
//             for(auto it = lower;it != nums2_mp.end();++it){
//                 if(it->second == nums1[i]){
//                     wallCheck = it->first;
//                     cout<<it->first<<" ";
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int count = 0;
        int m = nums1.size();
        int n = nums2.size();
        //dp[i][j] means the max uncrossed line when nums1 from 0 to i-1,and nums2 from 0 to j-1
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i = 1;i <= m;++i){
            for(int j = 1;j <= n;++j){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = dp[i-1][j]>dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
}; 