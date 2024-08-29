class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxValue = *max_element(nums.begin(),nums.end()); 
        int left = 0;
        long long res = 0;
        int maxCount = 0;

        for(int right = 0; right < nums.size();++right){
            if (nums[right] == maxValue) maxCount++;
            while (maxCount == k) {
                if (nums[left] == maxValue) maxCount--;
                left++;
            }
            res += left;
        }
        return res;
    }
};