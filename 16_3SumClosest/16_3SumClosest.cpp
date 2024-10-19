//two pointer, O(n^2)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res;
        int closest = nums[0] + nums[1] + nums[2];
        int dif = abs(target - closest); 
        sort(nums.begin(),nums.end());

        for(int i = 0;i < nums.size()-2;++i){
            int j = i + 1;
            int k = nums.size()-1;

            while(j < k){
                int curSum = nums[i] + nums[j] + nums[k];
                int curDif = abs(target - curSum);

                if (curSum == target)return target;
                else if (curSum < target)j++;
                else k--;

                if (curDif < dif) {
                    dif = curDif;
                    closest = curSum;
                }

            }
        }
        return closest;
    }
};