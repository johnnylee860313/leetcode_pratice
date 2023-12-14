//TLE
// class Solution {
// public:
//     bool checkSubarraySum(vector<int>& nums, int k) {
//         int slidesz = 2;
//         while(slidesz <= nums.size()){
//             for(int i = 0;i <= nums.size()-slidesz;++i){
//                 int sum = 0;
//                 for(int j = i;j < i+slidesz;++j){
//                     sum += nums[j];
//                 }
//                 if(sum%k == 0)return true;
//             }
//             slidesz++;
//         }
//         return false;
//     }
// };

//hashmap<remainder,index>, O(n)
class Solution{
public:
    bool checkSubarraySum(vector<int>& nums, int k){
        unordered_map<int,int> mp;
        mp[0] = -1;
        int sum = 0;

        for(int i = 0;i < nums.size();++i){
            sum += nums[i];
            sum %= k;

            if(mp.count(sum) > 0){
                // cout<<nums[i]<<" "<<sum<<" "<<i-mp[sum]<<endl;
                if(i-mp[sum] > 1)return true;
            }else mp[sum] = i;
        }
        return false;
    }
};