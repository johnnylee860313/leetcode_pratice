class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp_len(nums.size(),1);
        vector<int> dp_count(nums.size(),1);
        int mx = 0;
        int res = 0;

        for(int i = 0;i < nums.size();++i){
            for(int j = 0;j < i;++j){
                if(nums[j] < nums[i]){
                    if(dp_len[i] <= dp_len[j]){
                        dp_len[i] = dp_len[j]+1;
                        dp_count[i] = dp_count[j];
                    }else if(dp_len[i] == dp_len[j]+1){
                        dp_count[i] += dp_count[j];
                        // cout<<"count["<<i<<"] = "<<dp_count[i]<<endl;
                    }
                }
                // cout<<"dp["<<i<<"] = "<<dp_len[i]<<endl;
            }
            mx = max(mx, dp_len[i]);
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (mx == dp_len[i]) res += dp_count[i];
        }
        return res;
    }
};
// class Solution {
// public:
//     int findNumberOfLIS(vector<int>& nums) {
//         int res = 0, mx = 0, n = nums.size();
//         vector<int> len(n, 1), cnt(n, 1);
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < i; ++j) {
//                 if (nums[i] <= nums[j]) continue;
//                 if (len[i] == len[j] + 1) cnt[i] += cnt[j];
//                 else if (len[i] < len[j] + 1) {
//                     len[i] = len[j] + 1;
//                     cnt[i] = cnt[j];
//                 }
//             }
//             mx = max(mx, len[i]);
//         }
//         for (int i = 0; i < n; ++i) {
//             if (mx == len[i]) res += cnt[i];
//         }
//         return res;
//     }
// };