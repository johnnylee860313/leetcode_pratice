//O(logn)
// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int left = 0;
//         int right = nums.size()-1;
//         int mid = 0;

//         if (nums.size() == 1)return 0;

//         while(left < right) {
//             mid = left + (right-left)/2; //prevent left and right are the large integer,causing overflow
//             if(mid == 0)return nums[0]>nums[1]?0:1;
//             if( mid > 0 && mid < nums.size() && nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
//                 return mid;
//             }else if(mid > 0 && mid < nums.size() && nums[mid] < nums[mid+1]){
//                 left = mid+1;
//             }else if(mid > 0 && mid < nums.size() && nums[mid] < nums[mid-1]){
//                 right = mid-1;
//             }
//         }

//         return nums[mid]>nums[left]?mid:left;
//     }
// };
//O(logn)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;

        int left = 0, right = n - 1;
        while(left <= right) {
            int mid = left + (right-left)/2;

            if(mid > 0 && nums[mid] < nums[mid-1]) {
                right = mid - 1;
            }
            else if(mid < n-1 && nums[mid] < nums[mid+1]) {
                left = mid + 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};