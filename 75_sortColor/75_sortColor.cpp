// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         return sort(nums.begin(),nums.end());
//     }
// };


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        for (int i = 0; i <= end; ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[start++]);
            } else if (nums[i] == 2) {
                swap(nums[i--], nums[end--]);
            } 
        }
    }
};

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int left = 0, right = (int)nums.size() - 1, cur = 0;
//         while (cur <= right) {
//             if (nums[cur] == 0) {
//                 swap(nums[cur++], nums[left++]);
//             } else if (nums[cur] == 2) {
//                 swap(nums[cur], nums[right--]);
//             } else {
//                 ++cur;
//             }
//         }
//     }
// };