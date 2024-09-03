class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        double total = nums[0];
        int res = nums[0];

        for(int i = 1; i < nums.size();++i){
            total += nums[i];
            res = res > ceil(total/(i+1))?res:ceil(total/(i+1));
        }
        return res;
    }
};