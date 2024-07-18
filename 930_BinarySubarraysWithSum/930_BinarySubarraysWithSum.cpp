//O(n)
//O(1)
class Solution {
public:
    /*return num of subarray with less equal than sum */
    int numSubarrayLessEqualSum(vector<int>& nums,int goal){
        int count = 0;
        int temp_sum = 0;

        if(goal < 0)return 0;

        for(int left = 0,right = 0;right < nums.size();++right){
            temp_sum += nums[right];
            while(left <= right && temp_sum > goal){
                temp_sum -= nums[left++];
            }
            //window size means the number of subarray which ends with the last number in the window
            count += (right - left +1); 
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarrayLessEqualSum(nums,goal) - numSubarrayLessEqualSum(nums,goal-1);
    }
};