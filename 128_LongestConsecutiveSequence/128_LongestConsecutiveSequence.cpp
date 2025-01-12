class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(),nums.end());
        int longest = 0;
        
        for(auto num:nums){
            
                int length = 0;
                while(nums_set.find(num+length) != nums_set.end())length++;
                longest = max(length,longest);
            
        }
        
        return longest;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (int val : nums) {
            if (!s.count(val)) continue;
            s.erase(val);
            int pre = val - 1, next = val + 1;
            while (s.count(pre)) s.erase(pre--);
            while (s.count(next)) s.erase(next++);
            res = max(res, next - pre - 1);
        }
        return res;
    }
};