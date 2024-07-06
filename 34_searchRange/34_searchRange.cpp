//O(n)
// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         if(nums.size() == 0)return {-1,-1};
//         int l = 0;
//         int r = nums.size()-1;
//         vector<int> ans;

//         while(l <= r){
//             int mid = l + (r-l)/2;
//             if(nums[mid] > target){
//                 r = mid - 1;
//             }else if(nums[mid] < target){
//                 l = mid + 1;
//             }else if(nums[mid] == target){
//                 // cout<<mid<<" ";
//                 int start = mid;
//                 int end = mid;
//                 while((start-1 >= 0) && nums[start-1] == nums[mid])start--;
//                 while((end+1 < nums.size()) && nums[end+1] == nums[mid])end++;
//                 ans.push_back(start);
//                 ans.push_back(end);
//                 break;
//             }
//         }
//         if(ans.size() == 0){
//             ans.push_back(-1);
//             ans.push_back(-1);
//         }

//         return ans;
//     }
// };
//O(logn)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //find first number greater equal than target
        //then find the first number greater eual than target+1
        //Last, substract them
        int start = firstGreaterEqual(nums, target);
        if (start == nums.size() || nums[start] != target) return {-1, -1};
        return {start, firstGreaterEqual(nums, target + 1) - 1};
    }
    int firstGreaterEqual(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid-1;
        }
        return left;
    }
};