//O(n),two pointers
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k == 1)return 0;
        
        int res = INT_MAX;
        int left = 0;
        int right = k-1;//nums is 0 index
        sort(nums.begin(),nums.end());

        while(right < nums.size()){
            res = min(res,nums[right++]-nums[left++]);//the difference between largest and smallest
        }
        return res;
    }
};