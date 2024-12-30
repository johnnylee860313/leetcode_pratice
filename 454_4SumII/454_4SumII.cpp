//O(n^2)
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> sum_map1, sum_map2;
        int fourSumCount_res = 0;
        
        for(int i = 0;i <= nums1.size()-1;++i){
            for(int j = 0;j <= nums2.size()-1;++j){
                ++sum_map1[nums1[i]+nums2[j]];
                ++sum_map2[nums3[i]+nums4[j]];
            }
        }
        
        for(auto sum:sum_map1){
            fourSumCount_res += sum.second * sum_map2[-1*sum.first];
        }
        
        return fourSumCount_res;
    }
};