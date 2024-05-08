class Solution {
/* this question can be transfer to find the max result between 0 to n-2 and 1 to n-1 through dp */
/* TC : O(n) */
/* SC : O(1) */
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
        return max(findMax(nums,0,nums.size()-2),findMax(nums,1,nums.size()-1));
    }
    int findMax(vector<int>& nums,int start,int end){
        int even = 0;
        int odd = 0;

        for(int i = start;i <= end;++i){
            if(i % 2 == 0){
                even = max(odd, nums[i] + even);
            }else{
                odd = max(even, nums[i] + odd);
            }
        }
        return max(odd,even);
    }
};

