//O(n)
//O(1)
/*begin from the end of array , check if i-1 element can reach the i element or not each iteration*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size()-1;

        for(int i = nums.size()-1;i >= 0;--i){
            if (i + nums[i] >= goal) goal = i;
        }

        return goal==0?true:false;
    }
};