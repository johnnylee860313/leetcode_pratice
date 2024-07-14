//O(n)
/O(n)
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> diff_sum(nums.size(),-1);
        int total_sum = accumulate(nums.begin(),nums.end(),0);
        int left_sum = 0;
        int n = nums.size();

        for(int i = 0;i < nums.size();++i){
            int right_size = n - i - 1;
            int left_size = i;
            int right_sum = total_sum - left_sum - nums[i];

            diff_sum[i] = (left_size * nums[i] - left_sum) + (right_sum - right_size*nums[i]);  
            left_sum += nums[i];
        }

        return diff_sum;
    }
};