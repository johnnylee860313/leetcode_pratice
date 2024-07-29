//O(n),O(1)
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int window = 0;
        unordered_map<int,int> freq;

        for(int left = 0, right = 0; right < nums.size();++right){
            freq[nums[right]]++;

            while(left <= right && freq[nums[right]] > k) --freq[nums[left++]];
            

            window = window > (right-left+1)?window:(right-left+1);
        }
        return window;
    }
};