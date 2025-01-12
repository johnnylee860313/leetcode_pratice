class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> numCount;
        for(auto num:nums){
            numCount[num]++;
            if (numCount[num] > 1)return num;
        }
        return -1;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0, t = 0;
        while (true) { // find the cycle
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        while (true) {//find the entrance of the cycle
            slow = nums[slow];
            t = nums[t];
            if (slow == t) break;
        }
        return slow;
    }
};