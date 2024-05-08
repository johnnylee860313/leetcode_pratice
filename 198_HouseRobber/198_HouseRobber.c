/* 1D dp
    TC : O(n)
    SC : O(1)
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> rob(n,0);

        if(n == 1)return nums[0];
        
        rob[0] = nums[0];
        rob[1] = max(nums[0],nums[1]);

        for(int i = 2;i < n;i++){
            rob[i] = max(nums[i]+rob[i-2],rob[i-1]);
        }
        return rob[n-1];
    }
};