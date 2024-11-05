class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int smallest = INT_MAX;
        int smaller = INT_MAX;
        
        for(auto num:nums){
            if (num <= smallest) {
                smallest = num;
            } else if (num <= smaller) {
                smaller = num;
            } else {
                return true;
            }
        }
        return false;
    }
};

/*Wrong when [20,100,10,12,5,3]*/
// class Solution {
// public:
//     bool increasingTriplet(vector<int>& nums) {
//         int smallest = INT_MAX;
//         int count = 0;
        
//         for(int i = nums.size()-1;i >= 0;--i){
//             if (nums[i] < smallest){
//                 smallest = nums[i];
//                 count++;
//             }
//             if (count == 3)return true;
//         }
//         return false;
//     }
// };