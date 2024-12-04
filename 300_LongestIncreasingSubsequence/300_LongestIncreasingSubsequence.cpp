//O(N^2)
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         vector<int> LIS(nums.size(),1);
        
//         for(int i = nums.size()-1; i >= 0;--i){
//             for(int j = i+1; j < nums.size();++j){
//                 if (nums[i] < nums[j]){
//                     LIS[i] = max(LIS[i], 1+LIS[j]);
//                 }
//             }
//         }
//         return *max_element(LIS.begin(),LIS.end());
//     }
// };

//O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        // dp.push_back(nums[0]);
        
        for(int i = 0;i < nums.size();++i){
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]); //greater equal than nums[i] in dp
            
            if(it == dp.end())dp.push_back(nums[i]);
            else *it = nums[i];
            
        }
        for(auto n:dp){
            cout<<n<<endl;
        }
        return dp.size();
    }
};
