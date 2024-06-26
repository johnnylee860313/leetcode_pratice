class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 1;
        for(int i = 1;i < nums.size();++i){
            if(nums[i] < nums[i-1]){
                if(cnt == 0)return false;
                //[-1,4,2,3] or [4,2,3]
                if(i == 1 || nums[i] >= nums[i-2]){
                    nums[i-1] = nums[i];
                }else{
                    nums[i] = nums[i-1];
                }
                --cnt;
            }
        }
        return true;
    }
};