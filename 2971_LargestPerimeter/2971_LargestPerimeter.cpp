//O(nlogn)
//O(1)
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long res = -1;
        long long total = 0;

        sort(nums.begin(),nums.end());
        for(auto num:nums){
            if(total > num)res = total + num;
            total += num;
        }

        return res;
    }
};