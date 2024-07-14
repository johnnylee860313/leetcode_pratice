class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ra_arr(nums.size(),0);
        int pos = 0;
        int neg = 0;

        for(int i = 0;i < nums.size();++i){
            while(pos < nums.size() && nums[pos] < 0)pos++;
            while(neg < nums.size() && nums[neg] > 0 )neg++;
            if(i % 2 == 0){//even index, have to be positive num
                ra_arr[i] = nums[pos];
                pos++;
            }else {//odd index, have to be negative num
                ra_arr[i] = nums[neg];
                neg++;
            }
        }

        return ra_arr;
    }
};
