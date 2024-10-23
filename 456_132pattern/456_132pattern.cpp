//O(n),O(1)
//think about [1,6,5,4] -> below will find find 1,6,5
/* Ensure the largest and second largest number corresponded location relationship first
put the largest number so far into the stack, keep the second largest num */
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> stack_largest;
        int secondLargeNum = INT_MIN;
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (secondLargeNum > nums[i]) {
                return true;
            }
            
            while (!stack_largest.empty() && nums[i] > stack_largest.top()) {
                secondLargeNum = stack_largest.top();
                stack_largest.pop();
            }
            
            stack_largest.push(nums[i]);
        }
        
        return false;
    }
};