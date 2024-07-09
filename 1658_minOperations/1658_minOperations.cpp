/*sliding window
Find the max window which value accumulate to target.
target = nums sum - x
operation = nums size - window size
*/
//O(n)
//O(1)
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
       const int n =  nums.size();
       int target = 0;
       int sum = 0;
       int op = INT_MAX;
       for(auto num:nums){
        sum += num;
       }
       target = sum - x;
       
       for(int right = 0,left = 0, acc = 0;right < n;++right){
        acc += nums[right];
        while(acc > target && left <= right)acc -= nums[left++];
        if(acc == target)op = min(op,n-(right-left+1));
       }
       return op > n?-1:op;//if there is impossible to find target, op will remain to INT_MAX,have to be deal
    }
};