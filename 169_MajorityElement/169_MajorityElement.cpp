//O(n),O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0;
        int cnt = 0;
        
        for(auto num:nums){
            if (cnt == 0){
                res = num;
                cnt++;
            }else {
                if (res == num){
                    cnt++;
                }else{
                    cnt--;
                }
            }
        }
        return res;
    }
};